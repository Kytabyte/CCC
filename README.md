# CCC

This is a collection of my solution of [Canadian Computing Competition (CCC)](https://cemc.uwaterloo.ca/contests/computing.html).
The solutions are mainly written in C++. Python solutions will be updated gradually.

## Motivation

As starting to solving algorithmatic problem from LeetCode for seeking jobs, I didn't realize one day I would be in the hole of competitive programming deeply.
After I finished around 800 problems on LC, I feel like my body told me get the problems harder... Then I started to write Kick Start, Codejam, Codeforce, Hacker Cup
etc. And I luckily won a Codejam's T-shirt first time attending...

Finally, my coding skill was brought into teaching industry. I was asked if I could assist some young programmers on the coding and algorithm skills, and
definitely I am happy to be in. Now I am gradually clean up my solutions and post them here. Hope they're helpful!

## Contributing

Contribution on missing problems, optimization, simpifying code, and develop a remarkable different solution are more than welcomed. Just send PR and I will be active.
Thanks in advance.

## Testing

### Data

Test data could be found [here](https://cemc.uwaterloo.ca/contests/past_contests.html).

I put my data into `${year}/data/` folder. My following examples are based on this assumption.

### DMOJ

[DMOJ](https://dmoj.ca/problems/?search=CCC) has a mirror of CCC grader's test cases on all CCC problems.

### My Test Script

The `test.py` file is the my simple test script for checking the correctness of each question. Use `python3 test.py -h` to figure out the detailed usage.

- Requirement:
    - Python 3.6+ is required.
    - Linux works fine. Not tested for MacOS/Windows.

- Simple Usage: Pass `source-file`, `test-case-folder` and `language` arguments in. E.g.

    ```bash
    python3 test.py --source-file 2020/src/s4.cpp \
        --test-case-folder 2020/data/s4/ \
        --language cpp
    ```
    Supported languages are `cpp` and `py` for now.

- Other arguments:
    - Timeout option: use `--timeout` to specify the time limit to run each test case in seconds.
    Since the time limit is variant from CPU to CPU, please refer to the [How to set timeout](#How-to-set-timeout) section for details. The default time limit is 2 seconds.
    - For some numerical solution taking an answer as corrent when the difference
    between solution and answer is less than a threshold, use `--ans-threshold` argument. E.g. for 2020 s1, run

        ```bash
        python3 test.py --source-file 2020/src/s1.cpp \
            --test-case-folder 2020/data/s1/ \
            --language cpp \
            --ans-threshold 1e-6
        ```
    - For some questions do not have unique answer, I wrote a simple test script for each of them, at `year/test/problem.py`. Use `--test-file` argument to specify the test file. E.g. for 2019 s3, run

        ```bash
        python3 test.py --source-file 2019/src/s3.cpp \
            --test-case-folder 2019/data/s3 \
            --language cpp \
            --test-file 2019/test/s3.py
        ```

    - `--early-stop` to stop running the current test set when one case is failed. Default option is false.

#### How to set timeout

As the instructions in `example.cpp` to obtain the time limit you should set on your own computer. This is an estimation provided by CEMC officially.

**TL; DR;**

##### If your are using C++

- create a file called `in.txt` and write the following line into it.
    ```
    1
    11
    0
    ```
- Run following to compile
    ```bash
    g++ example.cpp
    ```
- Stopwatch the running time multiple times and use the `user` time for reference
    ```bash
    time ./a.out < in.txt
    ```

##### If your are using Python

- create a file called `in.txt` and write the following line into it.
    ```
    1
    9
    0
    ```
- Stopwatch the running time multiple times to estimate the time limit.
    Use the `user` time for reference
    ```bash
    time python3 example.py < in.txt
    ```

**Note**: From my personal observation using the c++ version to obtain the time limit is more accurate.

## Grade

Here listed the grade judged by myself and DMOJ. Since I don't have a CCC online grader account, I am not able to test on that platform. However, it will be much appreciated to help me test my code on CCC online grader platform.

**For Python code** It is clearly stated on the CCC official website that the problem is not designed to get full mark on all languages
even if an optimal solution is used, that is, for a scripting language like Python, it probably fail on some cases with large dataset.
However, a fairly good standing (not heading to CCO or IOI) can still be achieved with pure Python.

### 2015

| Problem # | Title                     | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J1        | Special Day               | 15/15    | 15/15 |                   |               |       |
| J2        | Happy or Sad              | 15/15    | 15/15 |                   |               |       |
| J3        | Rovarspraket              | 15/15    | 15/15 |                   |               |       |
| J4        | Wait Time                 | 15/15    | 15/15 |                   |               |       |
| J5        | π-day                     | 15/15    | 15/15 |                   |               |       |
| S1        | Zero That Out             | 15/15    | 15/15 |                   |               |       |
| S2        | Jerseys                   | 15/15    | 15/15 |                   |               |       |
| S3        | Gates                     | 15/15    | 30/30 |                   |               |       |
| S4        | Convex Hull               | 15/15    | 15/15 |                   |               |       |
| S5        | Greedy For Pies           | 15/15    | 15/15 |                   |               |       |

### 2016

| Problem # | Title                     | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J1        | Tournament Selection      | 15/15    | 15/15 |                   |               |       |
| J2        | Magic Squares             | 15/15    | 15/15 |                   |               |       |
| J3        | Hidden Palindrome         | 15/15    | 15/15 |                   |               | An adv O(N) solution TBO      |
| J4        | Arrival Time              | 15/15    | 15/15 |                   |               |       |
| J5/S2     | Tandem Bicycle            | 15/15    | 15/15 |                   |               |       |
| S1        | Ragaman                   | 15/15    | 15/15 |                   |               |       |
| S3        | Phonomenal Reviews        | 15/15    | 15/15 |                   |               |       |
| S4        | Combining Riceballs       | 15/15    | 15/15 |                   |               |       |
| S5        | Circle of Life            | 15/15    | 15/15 |                   |               |       |

### 2017

| Problem # | Title                     | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J1        | Quadrant Selection        | 15/15    | 15/15 |                   |               |       |
| J2        | Shifty Sum                | 15/15    | 15/15 |                   |               |       |
| J3        | Exactly Electrical        | 15/15    | 15/15 |                   |               |       |
| J4        | Favourite Times           | 15/15    | 15/15 |                   |               |       |
| J5/S3     | Nailed It!                | 15/15    | 15/15 |                   |               |       |
| S1        | Sum Game                  | 15/15    | 15/15 |                   |               |       |
| S2        | High Tide, Low Tide       | 15/15    | 15/15 |                   |               |       |
| S4        | Minimum Cost Flow         | 15/15    | 17/17 |                   |               |       |
| S5        | RMT                       | -/15     |  -/15 |                   |               | TBS   |

### 2018

| Problem # | Title                     | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J1        | Telemarketer or not?      | 15/15    | 15/15 |                   |               |       |
| J2        | Occupy parking            | 15/15    | 15/15 |                   |               |       |
| J3        | Are we there yet?         | 15/15    | 15/15 |                   |               |       |
| J4/S2     | Sunflowers                | 15/15    | 15/15 |                   |               |       |
| J5        | Choose your own path      | 15/15    | 15/15 |                   |               |       |
| S1        | Voronoi Villages          | 15/15    | 15/15 |                   |               |       |
| S3        | RoboThieves               | 15/15    | 15/15 |                   |               |       |
| S4        | Balanced Trees            |  5/15    |  5/15 |                   |               |  TBO  |
| S5        | Maximum Strategic Savings | 15/15    | 15/15 |                   |               |       |

### 2019

| Problem # | Title                         | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ----------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J1        | Winning Score                 | 15/15    | 15/15 |                   |               |       |
| J2        | Time to Decompress            | 15/15    | 15/15 |                   |               |       |
| J3        | Cold Compress                 | 15/15    | 15/15 |                   |               |       |
| J4/S1     | Flipper                       | 15/15    | 15/15 |                   |               |       |
| J5        | Rule of Three                 | 15/15    | 15/30 |                   |               | Fail on DMOJ's additional data |
| S2        | Pretty Average Primes         | 15/15    | 15/15 |                   |               |       |
| S3        | Arithmetic Square             | 15/15    | 16/16 |                   |               |       |
| S4        | Tourism                       |  -/15    |  -/15 |                   |               | TBS   |
| S5        | Triangle: The Data Structure  | 15/15    |  4/15 |                   |               | DMOJ has strict time limit      |

### 2020

| Problem # | Title                         | My Judge | DMOJ  | My Judge (Python) | DMOJ (Python) | Notes |
| --------- | ----------------------------- | -------- | ----- | ----------------- | ------------- | ----- |
| J2        | Epidemiology                  | 15/15    | 15/15 |  15/15            | 15/15         |       |
| J1        | Dog Treats                    | 15/15    | 15/15 |  15/15            | 15/15         |       |
| J3        | Art                           | 15/15    | 15/15 |  15/15            | 15/15         |       |
| J4        | Cyclic Shifts                 | 15/15    | 15/15 |  15/15            | 15/15         |       |
| J5/S2     | Escape Room                   | 15/15    | 15/15 |  13/15            | 13/15         |       |
| S1        | Surmising a Sprinter’s Speed  | 15/15    | 15/15 |  15/15            | 15/15         |       |
| S3        | Searching for Strings         | 15/15    | 15/15 |  15/15            | 15/15         |       |
| S4        | Swapping Seats                | 15/15    | 15/15 |  8/15             | 8/15          |       |
| S5        | Josh’s Double Bacon Deluxe    | 15/15    | 15/15 |  15/15            | 15/15         |  Optimized     |

**Note:**  
TBS: To be solved  
TBO: To be optimized

## Competitive Programming Resources

### YouTube Channel

Some CP YouTuber whose video I am drowning in watching. Good skills will be learnt from their vids.

- [William Lin](https://www.youtube.com/channel/UCKuDLsO0Wwef53qdHPjbU2Q)
- [Errichto](https://www.youtube.com/channel/UCBr_Fu6q9iHYQCh13jmpbrg)
