#include <bits/stdc++.h>

using namespace std;

/**
 *  To be optimized.
 * 
 *  Marks: 5/15
 */

typedef long long ll;
const int MAX_N = 1e8+5;
ll dp[MAX_N];

int main() {
  int N;
  cin >> N;

  dp[1] = 1;
  for (int i = 2; i <= N; i++) {
    dp[i] = 0;
    for (int j = i; j > 1; j--) {
      dp[i] += dp[i / j];
    }
  }
  cout << dp[N] << endl;

  return 0;
}