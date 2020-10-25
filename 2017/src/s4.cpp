#include <bits/stdc++.h>

using namespace std;

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

    void reset() {
      for (int i = 0; i < n; i++) {
          par[i] = i;
          rank[i] = 0;
      }
    }
};

struct Edge {
  int src, dst, cost, idx;
};

int main() {
  int n, m, d;
  cin >> n >> m >> d;

  vector<Edge> edges;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    edges.push_back({a-1, b-1, c, i});
  }
  sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) {
    if (e1.cost == e2.cost) {
      return e1.idx < e2.idx;
    }
    return e1.cost < e2.cost;
  });

  dsu uf(n);
  int ans = 0, last = -1;
  for (int i = 0; i < m; i++) {
    Edge e = edges[i];
    if (uf.merge(e.src, e.dst)) {
      last = i;
      if (e.idx >= n-1) {
        ans++;
      }
    }

    if (uf.part == 1) {
      break;
    }
  }

  if (edges[last].idx >= n-1) {
    int maxcost = edges[last].cost;
    uf.reset();
    for (Edge e : edges) {
      if (uf.find(e.src) == uf.find(e.dst)) {
        continue;
      }

      if (e.cost < maxcost || e.cost == maxcost && e.idx < n-1) {
        uf.merge(e.src, e.dst);
      } else if (e.idx < n - 1 && e.cost <= d) {
        ans--;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
