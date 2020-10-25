#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  sort(h.begin(), h.end());
  int lo, hi;
  if (n % 2 == 1) {
    lo = n / 2;
    hi = lo + 1;
  } else {
    hi = n / 2;
    lo = hi - 1;
  }

  vector<int> ans;
  for (int i = lo, j = hi; i >= 0; i--, j++) {
    ans.push_back(h[i]);
    if (j < n) {
      ans.push_back(h[j]);
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i < n - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }

  return 0;
}