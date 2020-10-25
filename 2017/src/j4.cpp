#include <bits/stdc++.h>

using namespace std;

int cnt[13] = {0, 1, 5, 5, 4, 4, 3, 3, 2, 2, 1, 0, 1};

int main() {
  int D;
  cin >> D;

  for (int i = 1; i < 13; i++) {
    cnt[i] += cnt[i-1];
  }

  int ans = D / (60 * 12) * cnt[12];
  D %= (60 * 12);

  int n = D / 60;
  ans += cnt[n];
  D %= 60;

  vector<int> t = {0, 0};
  if (n == 0) {
    n = 12;
  }

  while (n) {
    t.push_back(n % 10);
    n /= 10;
  }

  for (int i = 0; i <= D; i++) {
    t[0] = i % 10;
    t[1] = i / 10;

    bool valid = true;
    for (int j = 1; j < t.size(); j++) {
      if (t[j] - t[j-1] != t[1] - t[0]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}