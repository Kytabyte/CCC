# include <bits/stdc++.h>

using namespace std;

int main() {
  int p, n, r, d=0;
  cin >> p >> n >> r;
  int total = n;
  while (total < p) {
    n *= r;
    total += n;
    d++;
  }
  cout << d << endl;
  return 0;
}
