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

## Licence
The MIT License (MIT)

Copyright (c) 2013 Andrew Chase

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
