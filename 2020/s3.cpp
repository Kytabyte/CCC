#include <bits/stdc++.h>

/**
 * Marks: 15/15
 */

using namespace std;

const int MAX_N = 200000+5, N_H = 3;
string N, H;
int p[N_H] = {(int)1e9 + 7, (int)1e9+17, (int)((1 << 31) - 1)};
long pow26[N_H];

struct Hash {
  int cap, len=0, idx=0;
  long s1 = 0, s2 = 0, s3 = 0;
  vector<int> qu;

  Hash(int _cap) : cap(_cap) {
    qu.resize(cap);
  }

  void inc(int val) {
    s1 = (s1 * 26 + val) % p[0];
    s2 = (s2 * 26 + val) % p[1];
    s3 = (s3 * 26 + val) % p[2];
    if (len >= cap) {
      s1 = ((s1 - pow26[0] * qu[idx]) % p[0] + p[0]) % p[0];
      s2 = ((s2 - pow26[1] * qu[idx]) % p[1] + p[1]) % p[1];
      s3 = ((s3 - pow26[2] * qu[idx]) % p[2] + p[2]) % p[2];
    }
    qu[idx] = val;
    idx = (idx + 1) % cap;
    len++;
  }

  long code() {
    return s1 * 31 + s2 * 17 + s3 * 5;
  }
};


int main() {
  cin >> N >> H;

  for (int i = 0; i < N_H; i++) {
    pow26[i] = 1;
  }

  int n = N.size(), h = H.size();
  for (int i = 0; i < N_H; i++) {
    for (int j = 1; j < n+1; j++) {
      pow26[i] = pow26[i] * 26 % p[i];
    }
  }

  Hash hash(n);
  long ans = 0;

  int countN[26] = {0}, countH[26] = {0};
  unordered_set<long> seen;

  for (int i = 0; i < n; i++) {
    countN[N[i] - 'a']++;
  }

  for (int i = 0; i < h; i++) {
    countH[H[i] - 'a']++;
    hash.inc(H[i] - 'a');

    if (i < n - 1) {
      continue;
    }

    bool same = true;
    for (int j = 0; j < 26; j++) {
      if (countN[j] != countH[j]) {
        same = false;
        break;
      }
    }

    if (same && seen.find(hash.code()) == seen.end()) {
      seen.insert(hash.code());
      ans++;
    }
    countH[H[i-n+1] - 'a']--;
  }

  cout << ans << endl;

  return 0;
}