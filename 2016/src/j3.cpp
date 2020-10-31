#include <bits/stdc++.h>

using namespace std;

int expand(string& s, int lo, int hi) {
  int n = s.size();
  int ans = 0;
  for (int i = lo, j = hi; i >= 0 && j < n && s[i] == s[j]; i--, j++) {
    ans += 2;
  }
  return (lo == hi) ? ans - 1 : ans;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, expand(s, i, i));
    ans = max(ans, expand(s, i, i+1));
  }
  cout << ans << endl;

  return 0;
}
