#include <bits/stdc++.h>

using namespace std;

int main() {
    int L;
    cin >> L;

    string s;
    int cnt;
    char prev;
    for (int i = 0; i < L; i++) {
        cin >> s;
        cnt = 0;
        for (char ch : s) {
            if (cnt > 0 && ch != prev) {
                cout << cnt << ' ' << prev << ' ';
                cnt = 0;
            }
            prev = ch;
            cnt++;
        }
        cout << cnt << ' ' << prev << endl;
    }

    return 0;
}