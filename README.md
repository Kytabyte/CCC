# CCC

This is a collection of my solution of [Canadian Computing Competition (CCC)](https://cemc.uwaterloo.ca/contests/computing.html).
The solutions are mainly written in C++. Python solutions will be updated gradually.

## Contributing

Contribution on missing problems, wrong implementation, optimization, simpifying code, and develop a remarkable different solution are more than welcomed. Just send PR and I will be active.
Thanks in advance!

## Testing

### DMOJ

[DMOJ](https://dmoj.ca/problems/?search=CCC) has a mirror of CCC grader's test cases on all CCC problems.

### My Test Script

- Quick Usage

Suppose your source file and testing data folder is already on your disk, run the following command with **Python 3.6+**:

```bash
python test.py --src 2020/src/s4.cpp --data 2020/data/s4/ --lang cpp
```

- Full usage

See [this post](https://github.com/Kytabyte/CCC/blob/master/test.md), it supports other advanced arguments and testing approach (compare with threshold, test harness file, etc.)

## Grade

Here listed the grade judged by myself and DMOJ. Since I don't have a CCC online grader account, I am not able to test on that platform. However, it will be much appreciated to help me test my code on CCC online grader platform.

**For Python code** It is clearly stated on the CCC official website that the problem is not designed to get full mark on all languages
even if an optimal solution is used, that is, for a scripting language like Python, it probably fail on some cases with large dataset.
However, a fairly good standing (not heading to CCO or IOI) can still be achieved with pure Python.

### 2015

| Problem # | Title                     | C++      | Python | Notes |
| --------- | ------------------------- | -------- | ------ | ----- |
| J1        | Special Day               | 15/15    |        |       |
| J2        | Happy or Sad              | 15/15    |        |       |
| J3        | Rovarspraket              | 15/15    |        |       |
| J4        | Wait Time                 | 15/15    |        |       |
| J5        | π-day                     | 15/15    |        |       |
| S1        | Zero That Out             | 15/15    |        |       |
| S2        | Jerseys                   | 15/15    |        |       |
| S3        | Gates                     | 15/15    |        |       |
| S4        | Convex Hull               | 15/15    |        |       |
| S5        | Greedy For Pies           | 15/15    |        |       |

### 2016

| Problem # | Title                     | C++      | Python | Notes |
| --------- | ------------------------- | -------- | ------ | ----- |
| J1        | Tournament Selection      | 15/15    |        |       |
| J2        | Magic Squares             | 15/15    |        |       |
| J3        | Hidden Palindrome         | 15/15    |        | An adv O(N) solution TBO      |
| J4        | Arrival Time              | 15/15    |        |       |
| J5/S2     | Tandem Bicycle            | 15/15    |        |       |
| S1        | Ragaman                   | 15/15    |        |       |
| S3        | Phonomenal Reviews        | 15/15    |        |       |
| S4        | Combining Riceballs       | 15/15    |        |       |
| S5        | Circle of Life            | 15/15    |        |       |

### 2017

| Problem # | Title                     | C++      | Python | Notes |
| --------- | ------------------------- | -------- | ------ | ----- |
| J1        | Quadrant Selection        | 15/15    |        |       |
| J2        | Shifty Sum                | 15/15    |        |       |
| J3        | Exactly Electrical        | 15/15    |        |       |
| J4        | Favourite Times           | 15/15    |        |       |
| J5/S3     | Nailed It!                | 15/15    |        |       |
| S1        | Sum Game                  | 15/15    |        |       |
| S2        | High Tide, Low Tide       | 15/15    |        |       |
| S4        | Minimum Cost Flow         | 15/15    |        |       |
| S5        | RMT                       | -/15     |        | TBS   |

### 2018

| Problem # | Title                     | C++      | Python | Notes |
| --------- | ------------------------- | -------- | ------ | ----- |
| J1        | Telemarketer or not?      | 15/15    |        |       |
| J2        | Occupy parking            | 15/15    |        |       |
| J3        | Are we there yet?         | 15/15    |        |       |
| J4/S2     | Sunflowers                | 15/15    |        |       |
| J5        | Choose your own path      | 15/15    |        |       |
| S1        | Voronoi Villages          | 15/15    |        |       |
| S3        | RoboThieves               | 15/15    |        |       |
| S4        | Balanced Trees            | 15/15    |        |       |
| S5        | Maximum Strategic Savings | 15/15    |        |       |

### 2019

| Problem # | Title                         | C++      | Python | Notes |
| --------- | ----------------------------- | -------- | ------ | ----- |
| J1        | Winning Score                 | 15/15    |        |       |
| J2        | Time to Decompress            | 15/15    |        |       |
| J3        | Cold Compress                 | 15/15    |        |       |
| J4/S1     | Flipper                       | 15/15    |        |       |
| J5        | Rule of Three                 | 15/15    |        | DMOJ additional data TLE (15/30) |
| S2        | Pretty Average Primes         | 15/15    |        |       |
| S3        | Arithmetic Square             | 15/15    |        |       |
| S4        | Tourism                       | 15/15    |        |       |
| S5        | Triangle: The Data Structure  | 15/15    |        | See [v2](https://github.com/Kytabyte/CCC/blob/master/2019/src/s5_v2.cpp) for an O(N^2logK) sol to pass DMOJ      |

### 2020

| Problem # | Title                         | C++      | Python | Notes |
| --------- | ----------------------------- | -------- | ------ | ----- |
| J1        | Dog Treats                    | 15/15    |  15/15 |       |
| J2        | Epidemiology                  | 15/15    |  15/15 |       |
| J3        | Art                           | 15/15    |  15/15 |       |
| J4        | Cyclic Shifts                 | 15/15    |  15/15 |       |
| J5/S2     | Escape Room                   | 15/15    |  13/15 |       |
| S1        | Surmising a Sprinter’s Speed  | 15/15    |  15/15 |       |
| S3        | Searching for Strings         | 15/15    |  15/15 |       |
| S4        | Swapping Seats                | 15/15    |  8/15  |       |
| S5        | Josh’s Double Bacon Deluxe    | 15/15    |  15/15 |       |

### 2021

| Problem # | Title                         | C++      | Python | Notes |
| --------- | ----------------------------- | -------- | ------ | ----- |
| J1        | Boiling Water                 | 15/15    |        |       |
| J2        | Silent Auction                | 15/15    |        |       |
| J3        | Secret Instructions           | 15/15    |        |       |
| J4        | Arranging Books               | 15/15    |        |       |
| J5/S2     | Modern Art                    | 15/15    |        |       |
| S1        | Crazy Fencing                 | 15/15    |        |       |
| S3        | Lunch Concert                 | 15/15    |        |       |
| S4        | Daily Commute                 | 15/15    |        |       |
| S5        | Math Homework                 | 15/15    |        |       |

** Notes:
TBO: To be optimized  
TBS: To be solved

## Competitive Programming Resources

### YouTube Channel

Some CP YouTuber whose video I am drowning in watching. Good skills will be learnt from their vids.

- [William Lin](https://www.youtube.com/channel/UCKuDLsO0Wwef53qdHPjbU2Q)
- [Errichto](https://www.youtube.com/channel/UCBr_Fu6q9iHYQCh13jmpbrg)
