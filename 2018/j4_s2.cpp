#include <bits/stdc++.h>

using namespace std;

/**
 *  Could be simplified.
 * 
 *  Marks: 15/15
 */

int N;

bool deg0(vector<vector<int>>& grid) {
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (grid[i][j] < grid[i][j-1]) {
        return false;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    for (int i = 1; i < N; i++) {
      if (grid[i][j] < grid[i-1][j]) {
        return false;
      }
    }
  }

  return true;
}

bool deg90(vector<vector<int>>& grid) {
  for (int j = 0; j < N; j++) {
    for (int i = N - 2; i >= 0; i--) {
      if (grid[i][j] < grid[i+1][j]) {
        return false;
      }
    }
  }

  for (int i = N-1; i >= 0; i--) {
    for (int j = 1; j < N; j++) {
      if (grid[i][j] < grid[i][j-1]) {
        return false;
      }
    }
  }

  return true;
}

bool deg180(vector<vector<int>>& grid) {
  for (int i = N-1; i >= 0; i--) {
    for (int j = N-2; j >= 0; j--) {
      if (grid[i][j] < grid[i][j+1]) {
        return false;
      }
    }
  }

  for (int j = N-1; j >= 0; j--) {
    for (int i = N-2; i >= 0; i--) {
      if (grid[i][j] < grid[i+1][j]) {
        return false;
      }
    }
  }

  return true;
}

bool deg270(vector<vector<int>>& grid) {
  for (int j = N-1; j >= 0; j--) {
    for (int i = N - 2; i >= 0; i--) {
      if (grid[i][j] < grid[i+1][j]) {
        return false;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (grid[i][j] < grid[i][j-1]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  scanf("%d", &N);
  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  if (deg0(grid)) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << grid[i][j];
        if (j == N - 1) {
          cout << endl;
        } else {
          cout << ' ';
        }
      }
    }
  } else if (deg90(grid)) {
    for (int j = 0; j < N; j++) {
      for (int i = N - 1; i >= 0; i--) {
        cout << grid[i][j];
        if (i == 0) {
          cout << endl;
        } else {
          cout << ' ';
        }
      }
    }
  } else if (deg180(grid)) {
    for (int i = N - 1; i >= 0; i--) {
      for (int j = N - 1; j >= 0; j--) {
        cout << grid[i][j];
        if (j == 0) {
          cout << endl;
        } else {
          cout << ' ';
        }
      }
    }
  } else {
    for (int j = N - 1; j >= 0; j--) {
      for (int i = 0; i < N; i++) {
        cout << grid[i][j];
        if (i == N - 1) {
          cout << endl;
        } else {
          cout << ' ';
        }
      }
    }
  }

  return 0;
}