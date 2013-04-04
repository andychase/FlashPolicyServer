#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/socket.h>
#include <pthread.h>
#include <string.h>

#define MY_PORT     843
#define MAXBUF      1028
#define NUM_THREADS     1

int pipes[NUM_THREADS][2];
int sockfd;

const char *policy =
"<?xml version=\"1.0\"?>\n"
"<!DOCTYPE cross-domain-policy SYSTEM \"/xml/dtds/cross-domain-policy.dtd\">\n"
"<cross-domain-policy>\n"
"<site-control permitted-cross-domain-policies=\"master-only\"/>\n"
"<allow-access-from domain=\"*\" to-ports=\"*\" />\n</cross-domain-policy>\r\n";

void *SendPolicy(void *threadid) {
   int clientfd;
   int policy_size = strlen(policy);
   int tid;
   char buffer[MAXBUF];
   tid = (long) threadid;
   while(1) {
    /* --- Wait for, and recieve a client ---- */
    read(pipes[tid][0], &clientfd, sizeof(int), 0);

    /* --- Recieve --- */
    recv(clientfd, buffer, MAXBUF, 0);

    /* --- Send --- */
    send(clientfd, policy, policy_size, 0);

    /* --- Close ---*/
    close(clientfd);
   }
}

int main(int argc, char *argv[]) {
    /* --- Create worker threads --- */
    pthread_t threads[NUM_THREADS];
    int t;
    for(t=0; t<NUM_THREADS; t++) {
       pipe(pipes[t]); // <- Create pipes for sending clients
    	pthread_create(&threads[t], NULL, SendPolicy, (void *)t);
    }

    /* --- Create streaming socket --- */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)  {
    perror("Socket");
    return 1;
    }

    /* --- Initialize address/port structure --- */
    struct sockaddr_in self;
    self.sin_family = AF_INET;
    self.sin_port = htons(MY_PORT);
    self.sin_addr.s_addr = 0;
    self.sin_addr.s_addr = INADDR_ANY;
    self.sin_family = AF_INET;

    /* --- Assign a port number to the socket --- */
    if (bind(sockfd, (struct sockaddr*) &self, sizeof(self)) != 0 ) {
    	perror("Error: socket bind");
    	return 1;
    }

    /* --- Make it a "listening socket" --- */
    if ( listen(sockfd, 20) != 0 )    {
    	perror("socket--listen");
    	return 1;
    }

    struct sockaddr_in client_addr;
    int addrlen=sizeof(client_addr);
    int clientfd;
    int current_thread = 0;
    while (1) {
        /* --- Accept a client --- */
    clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);

    /* --- Send the client to a worker thread --- */
    write(pipes[current_thread][1], &clientfd, sizeof(int), 0);

    /* --- Cycle the threads --- */
    current_thread++;
    if (current_thread == NUM_THREADS)
        current_thread = 0;
    }

    /* --- Clean up --- */
    close(sockfd);
    pthread_exit(NULL);
    return 0;
}

