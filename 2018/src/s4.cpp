#include <bits/stdc++.h>

using namespace std;

/**
 *  Marks: 15/15
 */

typedef long long ll;
unordered_map<int, ll> memo;

ll solve(int n) {
  if (memo.count(n)) {
    return memo[n];
  }

  if (n == 1) {
    return memo[n] = 1;
  }

  ll ans = 0;
  for (int k = n, m, j; k > 1; k = j) {
    m = n / k, j = n / (m+1);
    ans += solve(m) * (k - j); // (k - j) subtrees with weight m 
  }
  return memo[n] = ans;
}

int main() {
  int N;
  cin >> N;

  ll ans = solve(N);
  cout << ans << endl;

  return 0;
}