#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

#define FLIGHT 0
#define PORTAL 1
typedef long long ll;
typedef tuple<ll, ll, ll, ll> t4; // cost, src, dst, type

struct dsu {
    int n;
    int part;
    vector<int> par;
    vector<int> rank;

    dsu(int _n) : n(_n), part(_n) {
        par = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank = vector<int>(n, 0);
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return false;
        }
        if (rank[px] > rank[py]) {
            par[py] = px;
        } else if (rank[px] < rank[py]) {
            par[px] = py;
        } else {
            par[py] = px;
            rank[px]++;
        }
        part--;
        return true;
    }
};

int main() {
    int N, M, P, Q;
    ll a, b, c;
    cin >> N >> M >> P >> Q;

    vector<t4> costs;
    ll total = 0;
    for (int i = 0; i < P; i++) {
        cin >> a >> b >> c;
        total += c * N;
        costs.push_back(make_tuple(c, a-1, b-1, FLIGHT));
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        total += c * M;
        costs.push_back(make_tuple(c, a-1, b-1, PORTAL));
    }

    sort(costs.begin(), costs.end());

    dsu e(M), f(N);
    ll best = 0;
    int type;
    for (t4 t : costs) {
        tie(c, a, b, type) = t;

        if (type == FLIGHT && e.merge(a, b)) {
            best += c * f.part;
        } else if (type == PORTAL && f.merge(a, b)) {
            best += c * e.part;
        }

        if (e.part == 1 && f.part == 1) {
            break;
        }
    }

    assert(e.part == 1 && f.part == 1);

    cout << total - best << endl;

    return 0;
}