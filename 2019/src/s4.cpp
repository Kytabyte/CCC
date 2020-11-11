#include <bits/stdc++.h>

using namespace std;

/**
 * Mark: 15/15
 */

#define read(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

const int MAXN = 1e6 + 5;
int N, K, a[MAXN], st[MAXN*4];
ll dp[MAXN];

void build(int i = 1, int tl = 1, int tr = N) {
    if (tl == tr) {
        st[i] = a[tl];
    } else {
        int mid = tl + (tr - tl) / 2;
        build(i*2, tl, mid);
        build(i*2+1, mid+1, tr);
        st[i] = max(st[i*2], st[i*2+1]);
    }
}

int query(int l, int r, int i = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return st[i];
    }
    int mid = tl + (tr - tl) / 2;
    return max(query(l, min(r, mid), i*2, tl, mid), 
                query(max(l, mid+1), r, i*2+1, mid+1, tr));
}

int main() {
    memset(st, 0, sizeof(st));
    memset(dp, -1, sizeof(dp));

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    build();

    int day = N/K + (N%K != 0);
    int less = day * K - N;

    dp[N] = 0;
    for (int d = 1; d <= day; d++) {
        int lmin = N - K*d, rmin = min(N, lmin + K);
        int r = min(N, rmin + less);

        for (int l = lmin + less; l >= max(lmin, 0); l--) {
            r = min(r, l+K);

            dp[l] = dp[r] + query(l+1, r);
            ll nxt;
            while (r > rmin && (nxt = dp[r-1] + query(l+1, r-1)) >= dp[l]) {
                dp[l] = nxt;
                r--;
            }
        }
    }   
    
    cout << dp[0] << endl;

    return 0;
}