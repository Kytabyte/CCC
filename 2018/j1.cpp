#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int digits[4];

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &digits[i]);
  }

  if (digits[0] != 8 && digits[0] != 9 || digits[3] != 8 && digits[3] != 9 || digits[1] != digits[2]) {
    cout << "answer" << endl;
  } else {
    cout << "ignore" << endl;
  }

  return 0;
}