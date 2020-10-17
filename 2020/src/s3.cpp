# include <bits/stdc++.h>

using namespace std;

int main() {
  string N, H;
  cin >> N >> H;

  if (N.size() > H.size()) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  set<string> seen;

  int n = N.size(), h = H.size();
  cout << n << ' ' << h << endl;
  int countN[26] = {0}, countH[26] = {0};
  for (int i = 0; i < n; i++) {
    countN[N[i] - 'a']++;
    countH[H[i] - 'a']++;
  }

  for (int i = n; i <= h; i++) {
    bool same = true;
    for (int j = 0; j < 26; j++) {
      if (countN[j] != countH[j]) {
        same = false;
        break;
      }
    }
    if (same && seen.find(H.substr(i-n, n)) == seen.end()) {
      seen.insert(H.substr(i-n, n));
      ans++;
    }

    if (i < h) {
      countH[H[i] - 'a']++;
      countH[H[i-n] - 'a']--;
    }
  }

  cout << ans << endl;

  return 0;
}
