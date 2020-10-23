#include <bits/stdc++.h>

using namespace std;

/**
 * This tedious dfs is somewhat stupid but it saves to think about
 * all different cases.
 * 
 * Marks: 15/15
 *        16/16 on DMOJ's enlarged test set
 */

int grid[3][3] = {0};
const int INF = 1e9;

bool full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == INF) {
                return false;
            }
        }
    }
    return true;
}

bool solved() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == INF) {
                return false;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (grid[i][0] - grid[i][1] != grid[i][1] - grid[i][2]) {
            return false;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (grid[0][j] - grid[1][j] != grid[1][j] - grid[2][j]) {
            return false;
        }
    }

    return true;
}

bool solve() {
    bool updated = true;
    int changed[3][3] = {0};
    while (!solved() && updated) {
        updated = false;
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != INF) {
                    cnt++;
                }
            }
            if (cnt == 2) {
                updated = true;
                if (grid[i][0] == INF) {
                    grid[i][0] = grid[i][1] * 2 - grid[i][2];
                    changed[i][0] = 1;
                } else if (grid[i][1] == INF) {
                    grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
                    changed[i][1] = 1;
                } else {
                    grid[i][2] = grid[i][1] * 2 - grid[i][0];
                    changed[i][2] = 1;
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                if (grid[i][j] != INF) {
                    cnt++;
                }
            }

            if (cnt == 2) {
                updated = true;
                if (grid[0][j] == INF) {
                    grid[0][j] = grid[1][j] * 2 - grid[2][j];
                    changed[0][j] = 1;
                } else if (grid[1][j] == INF) {
                    grid[1][j] = (grid[0][j] + grid[2][j]) / 2;
                    changed[1][j] = 1;
                } else {
                    grid[2][j] = grid[1][j] * 2 - grid[0][j];
                    changed[2][j] = 1;
                }
            }
        }
    }

    if (solved()) return true;
    if (full()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (changed[i][j]) {
                    grid[i][j] = INF;
                }
            }
        }
        return false;
    }

    for (int i = 0; i < 3; i++) {
        int idx = -1;
        bool fill = false;
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != INF) {
                idx = j;
            } else {
                fill = true;
            }
        }

        if (idx != -1 && fill) {
            int num = grid[i][idx];
            if (idx == 0) {
                grid[i][1] = num; grid[i][2] = num;
                if (solve()) {
                    return true;
                }
                grid[i][1] = num + 1; grid[i][2] = num + 2;
                if (solve()) {
                    return true;
                }
                grid[i][1] = INF; grid[i][2] = INF;
            } else if (idx == 1) {
                grid[i][0] = num; grid[i][2] = num;
                if (solve()) {
                    return true;
                }
                grid[i][0] = num - 1; grid[i][2] = num + 1;
                if (solve()) {
                    return true;
                }
                grid[i][0] = INF; grid[i][2] = INF;
            } else {
                grid[i][1] = num; grid[i][0] = num;
                if (solve()) {
                    return true;
                }
                grid[i][1] = num + 1; grid[i][0] = num + 2;
                if (solve()) {
                    return true;
                }
                grid[i][1] = INF; grid[i][0] = INF;
            }
            break;
        }
    }

    for (int j = 0; j < 3; j++) {
        int idx = -1;
        bool fill = false;
        for (int i = 0; i < 3; i++) {
            if (grid[i][j] != INF) {
                idx = i;
            } else {
                fill = true;
            }
        }

        if (idx != -1 && fill) {
            int num = grid[idx][j];
            if (idx == 0) {
                grid[1][j] = num; grid[2][j] = num;
                if (solve()) {
                    return true;
                }
                grid[1][j] = num + 1; grid[2][j] = num + 2;
                if (solve()) {
                    return true;
                }
                grid[1][j] = INF; grid[2][j] = INF;
            } else if (idx == 1) {
                grid[0][j] = num; grid[2][j] = num;
                if (solve()) {
                    return true;
                }
                grid[0][j] = num - 1; grid[2][j] = num + 1;
                if (solve()) {
                    return true;
                }
                grid[0][j] = INF; grid[2][j] = INF;
            } else {
                grid[1][j] = num; grid[0][j] = num;
                if (solve()) {
                    return true;
                }
                grid[1][j] = num + 1; grid[0][j] = num + 2;
                if (solve()) {
                    return true;
                }
                grid[1][j] = INF; grid[0][j] = INF;
            }
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (changed[i][j]) {
                grid[i][j] = INF;
            }
        }
    }

    return false;
}

int main() {
    string n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> n;
            if (n == "X") {
                grid[i][j] = INF;
            } else {
                grid[i][j] = stoi(n);
            }
        }
    }

    int ninf = 0, num = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == INF) {
                ninf++;
            } else {
                num = grid[i][j];
            }
        }
    }

    if (ninf >= 8) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = num;
            } 
        }
    }  else {
        bool ok = solve();
        assert(ok);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if (j == 2) {
                cout << endl;
            } else {
                cout << ' ';
            }
        }
    }
}