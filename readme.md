# Flash Policy Server

FINALLY a blazing fast, simple C Flash Policy server for a simple problem with emphasis on as little memory and highest speed as possible.

## How fast? 

    Concurrency Level:      1
    Time taken for tests:   28.226 seconds
    Complete requests:      100000
    Failed requests:        0
    Write errors:           0
    Total transferred:      25000000 bytes
    HTML transferred:       0 bytes
    Requests per second:    3542.88 [#/sec] (mean)
    Time per request:       0.282 [ms] (mean)
    Time per request:       0.282 [ms] (mean, across all concurrent requests)
    Transfer rate:          864.96 [Kbytes/sec] received
    
    
    Concurrency Level:      1000
    Time taken for tests:   80.562 seconds
    Complete requests:      33157
    Failed requests:        0
    Write errors:           2
    Total transferred:      8455500 bytes
    HTML transferred:       0 bytes
    Requests per second:    411.57 [#/sec] (mean)
    Time per request:       2429.701 [ms] (mean)
    Time per request:       2.430 [ms] (mean, across all concurrent requests)
    Transfer rate:          102.50 [Kbytes/sec] received

## Installation

1. clone or download zip
1. enter directory
2. make
3. chmod a+xX (if needed)
4. sudo ./policyserver &
