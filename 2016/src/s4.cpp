#include <bits/stdc++.h>

using namespace std;

const int MAXN= 400 + 5;
int balls[MAXN];
int presum[MAXN];
bool dp[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  presum[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> balls[i];
    presum[i+1] = presum[i] + balls[i];
  }

  for (int i = 0; i < N; i++) {
    dp[i][i] = 1;
    dp[i][i+1] = 1;
  }

  for (int d = 2; d <= N; d++) {
    for (int s = 0; s <= N - d; s++) {
      int e = s + d;

      int front = balls[s], back = balls[e-1];
      for (int i = s, j = e - 1; i < j; ) {
        if (dp[s][i+1] && dp[j][e] && dp[i+1][j] && front == back) {
          dp[s][e] = 1;
          break;
        }

        if (front < back) {
          i++;
          front += balls[i];
        } else {
          j--;
          back += balls[j];
        }
      }
    }
  }

  int ans = 0;
  for (int s = 0; s < N; s++) {
    for (int e = s + 1; e <= N; e++) {
      if (dp[s][e]) {
        ans = max(ans, presum[e] - presum[s]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}