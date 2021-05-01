#include <bits/stdc++.h>

using namespace std;

const int Mxn = 10005;
int h[Mxn], w[Mxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (h[i] + h[i+1]) * w[i];
  }

  cout << fixed << setprecision(1) << (double)ans / 2 << '\n';
  
  return 0;
}