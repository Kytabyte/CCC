/*  Canadian Computing Competition


   Example program to demonstrate input and output and time limit.


   Programming Language:  C++


   Specification:


      Write a program that reads several positive integers, one per
      line.  For each integer n, output the number of orderings
      possible for a set of n distinct values.  n will not exceed 11.
      The last line of input is indicated with n being 0.


   Sample Input:


      1
      11
      0


   Output for Sample Input:


      1
      39916800


   Implementation:


      The answer is n! (n factorial) which is easily computed in n steps.
      But this program does it the hard way.  It uses a recursive function
      to enumerate and count all the possible orderings.


   How to run the program:


      The program reads from "standard input" and writes to "standard output."
      That is, compile such as:
        g++ test.cc
      Then run the program as:
        ./a.out < input.txt
      or, if you wish to just type numbers at the program, run by
        ./a.out



   Run-time:

      Please time the execution time of this program on your computer,
      using the sample input.  This time is the maximum that should be
      allowed for any CCC program.


      On a 350 MHz processor, this program runs in about 15 seconds.
      (Your results will vary depending on processor, compiler, and
      compiler options.)


*/


#include <iostream>
#include <vector>

using namespace std;


int countfact(vector<int> &set, int n, int total) {
  
  int ret = 0;
  if (n == 0) {
    /* uncomment to print out each ordering */

    /* 
    for (int j=0; j<total; j++) cout << set[j] << " " ;
    cout << endl;
    */
    return 1;
  }

  for( int i = 0; i < n; i++ ) {
           swap( set[i], set[n-1] );
           ret += countfact( set, n-1, total );
           swap( set[i], set[n-1] );
  }
  return ret;
}


int main() {
        vector<int> set(11);
        int n;
        for( int i = 0; i < 11; i++ ) {
           set[i] = i+1;
        }
        while( cin >> n && n != 0 ) {
                cout << countfact(set, n, n) << endl;
        }

        return 0;
}
