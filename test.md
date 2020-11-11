# Usage of my test script

## Data

Test data could be found [here](https://cemc.uwaterloo.ca/contests/past_contests.html).

I put my data into `${year}/data/` folder. My following examples are based on this assumption.

The `test.py` file is the my simple test script for checking the correctness of each question. Use `python3 test.py -h` to figure out the detailed usage.

- Requirement:
    -- Python 3.6+ is required.
    -- Linux works fine. Not tested for MacOS/Windows.

- Basic Usage: Pass `src`, `data` and `lang` arguments in. E.g.

    ```bash
    python3 test.py --src 2020/src/s4.cpp \
        --data 2020/data/s4/ \
        --lang cpp
    ```

    Supported languages are `cpp` and `py` for now.

    `src` is your program file.  
    `data` is your test case folder.  
    `lang` is your programming language.  

- Other arguments:
    -- Timeout option: use `--timeout` to specify the time limit to run each test case in seconds.
    Since the time limit is variant from CPU to CPU, please refer to the [How to set timeout](#How-to-set-timeout) section for details. The default time limit is 2 seconds.
    -- For some numerical solution taking an answer as corrent when the difference
    between solution and answer is less than a threshold, use `--tol` (stands for tolerance) argument. E.g. for 2020 s1, run

    ```bash
    python3 test.py --src 2020/src/s1.cpp \
        --data 2020/data/s1/ \
        --lang cpp \
        --tol 1e-6
    ```

    -- For some questions do not have unique answer, I wrote a simple test harness script for each of them, at `year/test/problem.py`. Use `--harness` argument to specify the test file. E.g. for 2019 s3, run

    ```bash
    python3 test.py --src 2019/src/s3.cpp \
        --data 2019/data/s3 \
        --lang cpp \
        --harness 2019/test/s3.py
    ```

    -- `--early-stop` to stop running the current test set when one case is failed. Default option is false.

## How to set timeout

As the instructions in `example.cpp` to obtain the time limit you should set on your own computer. This is an estimation provided by CEMC officially.

**TL; DR;**

### If your are using C++

- create a file called `in.txt` and write the following line into it.

    ```txt
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

### If your are using Python

- create a file called `in.txt` and write the following line into it.

    ```txt
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
