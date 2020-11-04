#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000 + 5, MAXM = 100 + 5;
int N, M, A[MAXN], B[MAXM];
int memo[MAXN][MAXM][MAXM][2];

int dp(int i, int l, int r, int taken) {
  int& val = memo[i][l][r][taken];
  if (val >= 0) {
    return val;
  }

  val = 0;
  if (i == N && l > r) {
    return val;
  }

  if (taken) {
    if (i < N) {
      val = max(val, dp(i+1, l, r, 0));
    }
    if (l <= r) { 
      val = max(val, dp(i, l+1, r, 0));
    }
  } else {
    if (i < N) {
      val = max(val, A[i] + dp(i+1, l, r, 1));
      val = max(val, dp(i+1, l, r, 0));
    }
    if (l <= r) {
      val = max(val, B[r] + dp(i, l, r-1, 1));
    }
  }

  return val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo, -1, sizeof(memo));

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (int i = 1; i <= M; i++) {
    cin >> B[i];
  }

  sort(B+1, B+M+1);
  int ans = dp(0, 1, M, 0);
  cout << ans << endl;
  
  return 0;
}