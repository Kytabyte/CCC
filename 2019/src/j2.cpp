#include <bits/stdc++.h>

using namespace std;

int main() {
    int L;
    cin >> L;

    int n;
    char c;
    for (int i = 0; i < L; i++) {
        cin >> n >> c;
        for (int j = 0; j < n; j++) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}