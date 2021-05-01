#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int b; cin >> b;
  int p = 5*b-400;
  cout << p << '\n';
  if (p == 100) cout << 0 << '\n';
  else cout << (p<100 ? 1 : -1) << '\n';

  return 0;
}