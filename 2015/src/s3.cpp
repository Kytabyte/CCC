#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int g, p;
  cin >> g >> p;

  set<int> avail;
  for (int i = p; i >= 1; i--) {
    avail.insert(-i);
  }

  int n, ans = 0;
  for (int i = 0; i < p; i++) {
    cin >> n;
    auto it = avail.lower_bound(-n);
    if (it == avail.end()) {
      break;
    }
    ans++;
    avail.erase(it);
  }

  cout << ans << endl;
  
  return 0;
}