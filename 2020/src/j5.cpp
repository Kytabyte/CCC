# include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
map<int, vector<int>> factors;
int m, n;

void find_factor(int num) {
  for (int f = 1; f * f <= num; f++) {
    if (num % f == 0) {
      factors[num].push_back(f);
    }
  }
}

bool dfs(int r, int c) {
  if (r == m - 1 && c == n - 1) {
    return true;
  }

  int num = grid[r][c];
  if (!factors.count(num)) {
    find_factor(num);
  }
  for (int f : factors[num]) {
    int nr = f - 1, nc = num / f - 1;
    if (nr < m && nc < n && !visited[nr][nc]) {
      visited[nr][nc] = true;
      if (dfs(nr, nc)) {
        return true;
      }
      visited[nr][nc] = false;
    }
    nr = num / f - 1;
    nc = f - 1;
    if (nr < m && nc < n && !visited[nr][nc]) {
      visited[nr][nc] = true;
      if (dfs(nr, nc)) {
        return true;
      }
      visited[nr][nc] = false;
    }
  }
  return false;
}

void solve() {
  cin >> m >> n;
  grid = vector<vector<int>>(m, vector<int>(n, 0));
  visited = vector<vector<bool>>(n, vector<bool>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  visited[0][0] = true;
  bool ans = dfs(0, 0);
  cout << (ans ? "yes" : "no") << endl;
}

int main() {
  solve();
  return 0;
}

