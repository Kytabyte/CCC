#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> memo;

bool isprime(int num) {
    if (memo.count(num)) {
        return memo[num];
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return memo[num] = false;
        }
    }
    return memo[num] = true;
}

void solve(int num) {
    for (int i = num, j = num; i > 1; i--, j++) {
        if (isprime(i) && isprime(j)) {
            cout << i << ' ' << j << endl;
            return;
        }
    }
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        solve(N);
    }
    return 0;
}