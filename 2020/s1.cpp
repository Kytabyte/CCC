# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

void solve() {
  int n;
  cin >> n;
  map<int, int> pos;
  int t, x;
  for (int i = 0; i < n; i++) {
    cin >> t >> x;
    pos[t] = x;
  }

  t = -1;
  x = -1;
  double ans = 0;
  for (auto& p : pos) {
    if (t != -1) {
      ans = max(ans, abs(p.second - x) * 1.0 / (p.first - t)); 
    } 
    t = p.first;
    x = p.second;
  }

  cout << fixed << setprecision(9) << ans << endl;
}

int main() {
  solve();
  return 0;
}

