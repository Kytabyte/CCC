#include <bits/stdc++.h>

/**
 * Marks: 15/15
 *        4/15  on DMOJ
 */

using namespace std;

typedef long long ll;
const int MAXN = 3000+5;
int fw[MAXN][MAXN], grid[MAXN][MAXN];
int N, K;

int query(int r, int c) {
    int val = 0;
    for (int i = r + 1; i > 0; i -= i & -i) {
        for (int j = c + 1; j > 0; j -= j & -j) {
            val = max(val, fw[i][j]);
        }
    }
    return val;
}

void update(int r, int c, int v) {
    for (int i = r + 1; i <= N; i += i & -i) {
        for (int j = c + 1; j <= N; j += j & -j) {
            fw[i][j] = max(fw[i][j], v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    memset(fw, 0, sizeof(fw));

    for (int i = 0; i < N; i++) {
        for (int j = N-i-1; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      for (int j = i; j < N; j++) {
        int r = N - (j-i) - 1, c = j;
        update(r, c, grid[r][c]);

        if (N - r >= K) {
            ans += query(r + K - 1, c);
        }
      }
    }

    cout << ans << endl;
    return 0;
}