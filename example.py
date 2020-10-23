#   Canadian Computing Competition
#
#    Example program to demonstrate input and output and time limit.
#
#    Programming Language:  Python 3.x
#
#    Specification:
#
#       Write a program that reads several positive integers, one per
#       line.  For each integer n, output the number of orderings 
#       possible for a set of n distinct values.  n will not exceed 11.
#       The last line of input is indicated by 0.
#
#    Sample Input:
#
#       1
#       9
#       0
#
#    Output for Sample Input:
#
#       1
#       362880
#
#    Implementation:
#
#       The answer is n! (n factorial) which is easily computed in n steps.
#       But this program does it the hard way.  It uses a recursive function 
#       to enumerate and count all the possible orderings.
#
#    How to run the program:
#
#       The program reads from "standard input" and writes to "standard output."
#       Specifically, you can  this program with input by typing at the 
#       DOS command prompt (yes, you will need a Command Prompt window) 
#       in the correct directory (where you created the test.py2 file):
#                 python test2.py < input.txt
#       where input.txt contains the test data.  
#
#    Run-time:
#
#       Please time the execution time of this program on your computer, 
#       using the sample input.  This time is the maximum that should be
#       allowed for any CCC program.  Note that this solution will work
#       only up to problems of size 9 in the required time limit
#

def countfact(s, n, total):
  if (n == 0):
    # uncomment to print out each ordering
    #
    # for j in range(total): 
    #   print(s[j]," "),
    # print()
    return 1;

  r = 0
  for i in range(n):
    t = s[i]
    s[i] = s[n-1]
    s[n-1] = t
    r += countfact(s,n-1,total)
    s[n-1] = s[i]
    s[i] = t
  return r

######################################
## start of main function
set = [0]*11;

# initialize the set of values
for i in range(11):
  set[i] = i+1;
n = 1
while (n > 0):    #  0 would do nothing, and -1 is nothing to read
  n = int(input())
  if (n>0):
    print(countfact(set,n,n))


######################################################################
## For comparison, here is a slightly more efficient solution
##
##import itertools  # allows importing of permutations
##
##n = 1
##while (n > 0):    #  0 would do nothing, and -1 is nothing to read
##  n = int(raw_input())
##  if (n>0):
##    all_permutations = list(itertools.permutations(range(n)))
##    # uncomment to see all the permutations
##    #
##    #for perm in all_permutations:
##    #  print(perm)
##
##    print(len(all_permutations))
##
