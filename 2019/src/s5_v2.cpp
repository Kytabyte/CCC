#include <bits/stdc++.h>

/**
 * Marks: 15/15
 */

using namespace std;

typedef long long ll;
const int MAXN = 3000+5;
int grid[MAXN][MAXN];
int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> grid[i][j];
        }
    }

    // by comparing three corners with offset m, grid[i][j] will have max value of a triangle with size k
    int k = 2, m = 1; 
    while (k <= K) {
        for (int i = 0; i < N - k + 1; i++) {
            for (int j = 0; j <= i; j++) {
                grid[i][j] = max(grid[i][j], max(grid[i+m][j], grid[i+m][j+m]));
            }
        }

        if (k == K) {
            break;
        }
        int row = k/2 + 1; // max row to cover all points
        m = k - row + 1;
        if (k + m > K) {
            m = K - k;
            k = K;
        } else {
            k += m;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N - K + 1; i++) {
        for (int j = 0; j <= i; j++) {
            ans += grid[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}