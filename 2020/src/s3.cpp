#include <bits/stdc++.h>

/**
 * Marks: 15/15
 */

using namespace std;

typedef long long ll;

const int M1 = 1e9 + 7, M2 = 1e9 + 17;
int cntN[26], cntH[26];

ll code(ll h1, ll h2) {
  return h1 * 31 + h2 * 5;
}

int main() {
  memset(cntN, 0, sizeof(cntN));
  memset(cntH, 0, sizeof(cntH));

  string N, H;
  cin >> N >> H;

  for (char ch : N) {
    cntN[ch - 'a']++;
  }

  int n = N.size(), h = H.size();
  ll h1 = 0, h2 = 0;
  ll p1 = 1, p2 = 1;
  for (int i = 0; i < n-1; i++) {
    p1 = p1 * 26 % M1;
    p2 = p2 * 26 % M2;
  }
  
  int ans = 0;
  unordered_set<ll> seen;
  for (int i = 0; i < h; i++) {
    cntH[H[i] - 'a']++;
    h1 = (h1 * 26 + (H[i] - 'a')) % M1;
    h2 = (h2 * 26 + (H[i] - 'a')) % M2;

    if (i < n - 1) {
      continue;
    }

    bool same = true;
    for (int j = 0; j < 26; j++) {
      if (cntN[j] != cntH[j]) {
        same = false;
        break;
      }
    }

    if (same && seen.find(code(h1, h2)) == seen.end()) {
      seen.insert(code(h1, h2));
      ans++;
    }
    cntH[H[i-n+1] - 'a']--;
    h1 = ((h1 - p1 * (H[i-n+1] - 'a')) % M1 + M1) % M1;
    h2 = ((h2 - p2 * (H[i-n+1] - 'a')) % M2 + M2) % M2;
  }

  cout << ans << endl;

  return 0;
}