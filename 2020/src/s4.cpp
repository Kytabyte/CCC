# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

const int MAXN = 1e6+5;
int ps[3][MAXN];
string s;
int N, ans = MAXN;

bool avail[3];
int cand[3];

int query(int i, int s, int l) {
  return ps[i][s+l] - ps[i][s];
}

void solve(int a, int b, int c) {
  int Na = ps[a][N], Nb = ps[b][N];
  int Nab = Na + Nb;

  for (int i = 0; i <= N - Nab; i++) {
    int na = query(a, i, Nab), nb = query(b, i, Nab), nc = query(c, i, Nab);
    int da = Na-na, db = Nb-nb;

    int fa = query(a, i, Na), fca = query(c, i, Na);
    int fb = query(b, i, Nb), fcb = query(c, i, Nb);

    int cur = nc + min(Na - (fa + min(da, fca)), Nb - (fb + min(db, fcb)));
    ans = min(ans, cur);
  }
}

void dfs(int cur) {
  if (cur == 3) {
    solve(cand[0], cand[1], cand[2]);
  }

  for (int i = 0; i < 3; i++) {
    if (avail[i]) {
      avail[i] = false;
      cand[cur] = i;
      dfs(cur+1);
      avail[i] = true;
    }
  }
}

int main() {
  cin >> s;
  N = s.size();

  for (int i = 0; i < 3; i++) {
    ps[i][0] = 0;
    for (int j = 1; j <= N; j++) {
      ps[i][j] = ps[i][j-1] + (s[j-1] - 'A' == i);
    }
  }

  memset(avail, 1, sizeof(avail));

  dfs(0);
  cout << ans << endl;

  return 0;
}

