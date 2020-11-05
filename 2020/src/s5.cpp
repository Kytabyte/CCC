# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

const int MAXN = 1e6+5, MAXM = 5e5+5;
int N, bur[MAXN], last[MAXM];
double pr[MAXM];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> bur[i];
    last[bur[i]] = i;
  }

  memset(pr, 0, sizeof(pr));

  int c = bur[0], j = bur[N-1];
  if (c == j) {
    cout << 1 << endl;
    return 0;
  }

  pr[c] = 1.0;
  double total = 1.0;
  for (int i = N-1; i >= 1; i--) {
    int b = bur[i];
    if (last[b] == i && b != c && b != j) {
      pr[b] = total / (N-i);
    }
    total += pr[b];
  }

  double ans = total / N;
  cout << fixed << ans << endl;

  return 0;
}