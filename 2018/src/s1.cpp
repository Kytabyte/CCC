#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

const int INF = 2e9;

int main() {
  int N;
  scanf("%d", &N);

  vector<double> v(N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i]);
  }
  sort(v.begin(), v.end());

  double ans = INF;
  for (int i = 1; i < N - 1; i++) {
    ans = min(ans, (v[i] - v[i-1]) / 2 + (v[i+1] - v[i]) / 2);
  }
  
  cout << fixed << setprecision(1) << ans << endl;

  return 0;
}