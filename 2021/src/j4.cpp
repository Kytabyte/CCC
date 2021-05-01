#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int ans = 0, n = s.size();

  // count how many L and S are there
  int cntL = 0, cntS = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      cntL++;
    } else if (s[i] == 'S') {
      cntS++;
    }
  }

  // swap all L within [0, cntL] and S within [n-cntS, n) first
  // make sure only L-M swap and S-M swap needed after this step
  for (int l = 0, r = n-1; l < cntL && r >= n-cntS; ) {
    while (l < r && s[l] != 'S') {
      l++;
    }
    while (l < r && s[r] != 'L') {
      r--;
    }

    if (l < cntL && r >= n-cntS) {
      swap(s[l], s[r]);
      ans++;
    }
  }

  // swap wrong order of L and M
  for (int l = 0; l < cntL; l++) {
    if (s[l] != 'L') {
      ans++;
    }
  }

  // swap wrong order of S and M
  for (int r = n-cntS; r < n; r++) {
    if (s[r] != 'S') {
      ans++;
    }
  }
  
  cout << ans << '\n';

  return 0;
}