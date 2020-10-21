#include <bits/stdc++.h>

/**
 * Marks: 15/15
 *        4/15  on DMOJ
 */

using namespace std;

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

    printf("%lld\n", ans);
    return 0;
}