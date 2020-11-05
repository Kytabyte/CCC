# include <bits/stdc++.h>

/**
 * Marks: 15/15
 */

using namespace std;

const int MAXN = 1000 + 5, MAXK = 1e6+5;
int grid[MAXN][MAXN];
vector<int> factors[MAXK];
int m, n;

void find_factor(int num) {
  for (int f = 1; f * f <= num; f++) {
    if (num % f == 0 && f <= max(m, n) && num / f <= max(m, n)) {
      factors[num].push_back(f);
    }
  }
}

bool dfs(int r, int c) {
  if (r == m - 1 && c == n - 1) {
    return true;
  }

  if (r >= m || c >= n || !factors[grid[r][c]].empty()) {
    return false;
  }

  int num = grid[r][c];
  find_factor(num);

  for (int f : factors[num]) {
    int nr = f - 1, nc = num / f - 1;
    if (dfs(nr, nc) || dfs(nc, nr)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  bool ans = dfs(0, 0);
  cout << (ans ? "yes" : "no") << endl;
  return 0;
}
