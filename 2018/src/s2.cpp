#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) cerr << " [" << #__VA_ARGS__  << ": " << (__VA_ARGS__) << "] "
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> p) {
  return s << " (" << p.first << "," << p.second << ") ";
}
template<typename T> ostream& operator<<(ostream& s, vector<T> v) {
  s << "size: " << v.size() << " {";
  for (T& t : v) {
    s << t << " ";
  }
  s << "} ";
  return s;
}
template<typename T> ostream& operator<<(ostream& s, vector<vector<T>> m) {
  s << "shape: " << m.size() << 'x' << m[0].size() << endl;
  for (vector<T>& r : m) {
    for (T& t : r) {
      cout << t << ' ';
    }
    cout << endl;
  }
  return s;
}

int N;

bool deg0(vector<vector<int>>& grid) {
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (grid[i][j] < grid[i][j-1]) {
        // DEBUG(i); DEBUG(j); cout <<'1'<< endl;
        return false;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    for (int i = 1; i < N; i++) {
      if (grid[i][j] < grid[i-1][j]) {
        // DEBUG(i); DEBUG(j); cout <<'2'<< endl;
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