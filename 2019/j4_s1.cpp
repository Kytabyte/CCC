#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int main() {
    string s;
    cin >> s;

    bool h = false, v = false;
    for (char ch : s) {
        if (ch == 'H') {
            h = !h;
        } else {
            v = !v;
        }
    }

    int out[2][2] = {1,2,3,4};
    if (h) {
        swap(out[0], out[1]);
    }

    if (v) {
        swap(out[0][0], out[0][1]);
        swap(out[1][0], out[1][1]);
    }

    cout << out[0][0] << ' ' << out[0][1] << endl;
    cout << out[1][0] << ' ' << out[1][1] << endl;

    return 0;
}