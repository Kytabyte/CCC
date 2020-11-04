#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250 + 5;
int memo[MAXN][MAXN][MAXN];

int dp(int n, int k, int m) {
  int& val = memo[n][k][m];
  if (val >= 0) {
    return val;
  }

  if (k == 1) {
    return val = (m > n) ? 0 : 1;
  }

  if (n == k) {
    return val = (m == 1) ? 1 : 0;
  }

  val = 0;
  for (int i = m; i <= n - k + 1; i++) {
    val += dp(n - i, k - 1, i);
  }
  return val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  memset(memo, -1, sizeof(memo));
  
  int ans = dp(n, k, 1);
  cout << ans << endl;
  
  return 0;
}