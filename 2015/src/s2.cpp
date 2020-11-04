#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int sz[MAXN];

map<char, int> mp = {
  {'S', 0},
  {'M', 1},
  {'L', 2}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int j, a;
  cin >> j >> a;

  char s;
  int n;
  for (int i = 1; i <= j; i++) {
    cin >> s;
    sz[i] = mp[s];
  }

  int ans = 0;
  for (int i = 0; i < a; i++) {
    cin >> s >> n;
    if (mp[s] <= sz[n]) {
      ans++;
      sz[n] = -1;
    }
  }

  cout << ans << endl;
  
  return 0;
}