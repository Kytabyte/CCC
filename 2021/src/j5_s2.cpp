#include <bits/stdc++.h>

using namespace std;

/** Analysis
 * 
 * The number of flips at index (r, c) should be 
 * the number of flips on row r + the number of flips on column c
 * 
 * So we only need to check the flip status for each row and column.
 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, k; cin >> m >> n >> k;

  // color of each row and each column. 0 means black, 1 means golden
  vector<int> rows(m, 0), cols(n, 0);

  for (int i = 0; i < k; i++) {
    char ch; 
    int idx;
    cin >> ch >> idx;
    idx--;

    if (ch == 'R') {
      rows[idx] ^= 1;
    } else {
      cols[idx] ^= 1;
    }
  }

  int ans = 0;
  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      if (rows[r] ^ cols[c]) {
        ans++;
      }
    }
  }

  cout << ans << '\n';
  
  return 0;
}