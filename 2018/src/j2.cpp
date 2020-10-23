#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int main() {
  int n;
  string last, cur;
  // scanf("%d%s%s", &n, &last, &cur);
  cin >> n >> last >> cur;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (last[i] == 'C' && cur[i] == 'C') {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}