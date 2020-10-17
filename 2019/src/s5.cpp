// #include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;

#define DEBUG(...) cerr << "[" << #__VA_ARGS__  << ": " << (__VA_ARGS__) << "] "
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

typedef long long ll;

struct Fenwick_2d {
    vector<vector<int>> grid;
    int N, M;

    Fenwick_2d(int _n, int _m) : N(_n), M(_m) {
        grid = vector<vector<int>>(_n+1, vector<int>(_m+1, 0));
    }

    void update(int r, int c, int val) {
        for (int i = r + 1; i <= N; i += i & -i) {
            for (int j = c + 1; j <= M; j += j & -j) {
                grid[i][j] = max(grid[i][j], val);
            }
        }
    }

    int query(int r, int c) {
        int val = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                val = max(val, grid[i][j]);
            }
        }
        return val;
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = N-i-1; j < N; j++) {
            // cin >> grid[i][j];
            scanf("%d", &grid[i][j]);
        }
    }

    Fenwick_2d fw(N, N);
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      for (int j = i; j < N; j++) {
        int r = N - (j-i) - 1, c = j;
        fw.update(r, c, grid[r][c]);

        if (N - r >= K) {
          ans += fw.query(r + K - 1, c);
        }
      }
    }

    // cout << ans << endl;
    printf("%lld", ans);
    return 0;
}