#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char s;
  int x, m, t = 0;
  int inf = 2e6;

  cin >> m;
  
  char p = ' ';
  map<int, int> ans;
  for (int i = 0; i < m; i++) {
    cin >> s >> x;
    if (s == 'W') {
      t += x;
    } else {
      if (p != 'W') {
        t += 1;
      }
      if (s == 'R') {
        ans[x] -= (t + inf);
      } else {
        ans[x] += (t + inf);
      }
    }
    p = s;
  }

  for (auto& p : ans) {
    cout << p.first << ' ';
    if (p.second < 0) {
      cout << -1 << endl;
    } else {
      cout << p.second << endl;
    }
  }
  return 0;
}