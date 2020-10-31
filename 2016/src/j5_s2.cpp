#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n;
  cin >> t >> n;
  vector<int> d(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(d.begin(), d.end());
  if (t == 1) 
    sort(p.begin(), p.end());
  else 
    sort(p.rbegin(), p.rend());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += max(d[i], p[i]);
  }
  cout << ans << endl;
  return 0;
}