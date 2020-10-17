#include <bits/stdc++.h>

using namespace std;

int grid[3][3] = {0};
const int INF = 1e9;

bool solved() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == INF) {
                return false;
            }
        }
    }
    return true;
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

    bool updated = true;
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
                } else if (grid[i][1] == INF) {
                    grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
                } else {
                    grid[i][2] = grid[i][1] * 2 - grid[i][0];
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
                } else if (grid[1][j] == INF) {
                    grid[1][j] = (grid[0][j] + grid[2][j]) / 2;
                } else {
                    grid[2][j] = grid[1][j] * 2 - grid[0][j];
                }
            }
        }
    }

    

    if (!solved()) {
        for (int i = 0; i < 3; i++) {
            int num = INF;
            bool fill = false;
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != INF) {
                    num = grid[i][j];
                } else {
                    fill = true;
                }
            }

            if (num != INF && fill) {
                for (int j = 0; j < 3; j++) {
                    grid[i][j] = num;
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            int num = INF;
            bool fill = false;
            for (int i = 0; i < 3; i++) {
                if (grid[i][j] != INF) {
                    num = grid[i][j];
                } else {
                    fill = true;
                }
            }

            if (num != INF && fill) {
                for (int i = 0; i < 3; i++) {
                    grid[i][j] = num;
                }
            }
        }
    }

    if (!solved()) {
        memset(grid, 0, 9*sizeof(int));
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