#include <bits/stdc++.h>

using namespace std;

int main() {
    int a3, a2, a1, b3, b2, b1;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    int a = a3*3 + a2*2 + a1*1;
    int b = b3*3 + b2*2 + b1*1;

    if (a > b) {
        cout << 'A' << endl;
    } else if (a < b) {
        cout << 'B' << endl;
    } else {
        cout << 'T' << endl;
    }
    return 0;
}