# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int main() {
  int p, n, r, d=0;
  cin >> p >> n >> r;
  int total = n;
  while (total <= p) {
    n *= r;
    total += n;
    d++;
  }
  cout << d << endl;
  return 0;
}
