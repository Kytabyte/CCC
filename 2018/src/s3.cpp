#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

const int MAX_N = 100 + 5;
char grid[MAX_N][MAX_N];
int N, M;

typedef pair<int, int> pii;
const int dx4[4] = {-1, 1, 0, 0};
const int dy4[4] = {0, 0, 1, -1};

bool chk_camera(int r, int c) {
  for (int j = c - 1; j >= 0 && grid[r][j] != 'W'; j--) {
    if (grid[r][j] == 'C') {
      return false;
    }
  }

  for (int j = c + 1; j < M && grid[r][j] != 'W'; j++) {
    if (grid[r][j] == 'C') {
      return false;
    }
  }

  for (int i = r - 1; i >= 0 && grid[i][c] != 'W'; i--) {
    if (grid[i][c] == 'C') {
      return false;
    }
  }

  for (int i = r + 1; i < N && grid[i][c] != 'W'; i++) {
    if (grid[i][c] == 'C') {
      return false;
    }
  }

  return true;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", grid[i]);
  }

  pii start;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'S') {
        start = make_pair(i, j);
      }
    }
  }

  vector<vector<int>> ans(N, vector<int>(M, -1));
  vector<vector<bool>> seen(N, vector<bool>(M, false));
  queue<pii> qu;
  qu.push(start);
  seen[start.first][start.second] = true;

  // if the row/col of the start has camera, no points can be reached
  if (chk_camera(start.first, start.second)) {
    int step = 0;
    while (!qu.empty()) {
      int n = qu.size();
      for (int i = 0; i < n; i++) {
        pii cur = qu.front(); qu.pop();
        if (grid[cur.first][cur.second] == '.') {
          ans[cur.first][cur.second] = step;
        }

        for (int d = 0; d < 4; d++) {
          pii nxt = make_pair(cur.first + dx4[d], cur.second + dy4[d]);
          if (seen[nxt.first][nxt.second]) {
            continue;
          }
          char ch = grid[nxt.first][nxt.second];
          while (!seen[nxt.first][nxt.second] && ch != '.' && ch != 'W' && ch != 'C') {
            seen[nxt.first][nxt.second] = true;
            if (ch == 'L') {
              nxt.second--;
            } else if (ch == 'R') {
              nxt.second++;
            } else if (ch == 'U') {
              nxt.first--;
            } else if (ch == 'D') {
              nxt.first++;
            }
            ch = grid[nxt.first][nxt.second];
          }

          if (seen[nxt.first][nxt.second]) {
            continue;
          }

          seen[nxt.first][nxt.second] = true;
          bool valid = (ch == '.') && chk_camera(nxt.first, nxt.second);

          if (valid) {
            qu.push(nxt);
          }
        }
      }
      step++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == '.') {
        cout << ans[i][j] << endl;
      }
    }
  }
  
  return 0;
}
