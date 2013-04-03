# Flash Policy Server

FINALLY a blazing fast, simple C Flash Policy server for a simple problem with emphasis on as little memory and highest speed as possible.

## How fast? 

    Concurrency Level:      10
    Time taken for tests:   4.953 seconds
    Complete requests:      31658
    Failed requests:        0
    Write errors:           0
    Total transferred:      7914500 bytes
    HTML transferred:       0 bytes
    Requests per second:    6391.32 [#/sec] (mean)
    Time per request:       1.565 [ms] (mean)
    Time per request:       0.156 [ms] (mean, across all concurrent requests)
    Transfer rate:          1560.38 [Kbytes/sec] received
    
    
    
    Concurrency Level:      1000
    Time taken for tests:   23.792 seconds
    Complete requests:      7875
    Failed requests:        0
    Write errors:           0
    Total transferred:      1975000 bytes
    HTML transferred:       0 bytes
    Requests per second:    330.99 [#/sec] (mean)
    Time per request:       3021.252 [ms] (mean)
    Time per request:       3.021 [ms] (mean, across all concurrent requests)
    Transfer rate:          81.06 [Kbytes/sec] received


## Installation

1. clone or download zip
1. enter directory
2. make
3. chmod a+xX (if needed)
4. sudo ./policyserver &