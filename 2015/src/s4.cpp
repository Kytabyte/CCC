#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int node, time, hull;
};

bool operator<(const Edge& a, const Edge& b) {
  if (a.time == b.time) {
    return a.hull < b.hull;
  }
  return a.time > b.time;
}

const int MAXN = 2000 + 5, MAXK = 200 + 5, INF = 0x3f;
int dist[MAXN][MAXK];
vector<Edge> graph[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dist, INF, sizeof(int) * MAXN * MAXK);
  
  int k, n, m;
  int a, b, t, h;

  cin >> k >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> t >> h;
    graph[a-1].push_back({b-1, t, h});
    graph[b-1].push_back({a-1, t, h});
  }

  int src, dst;
  cin >> src >> dst;
  src--; dst--;

  priority_queue<Edge> pq;
  pq.push({src, 0, k});
  while (!pq.empty()) {
    Edge u = pq.top(); pq.pop();
    if (u.node == dst) {
      cout << u.time << endl;
      return 0;
    }
    for (Edge v : graph[u.node]) {
      if (v.hull < u.hull && u.time + v.time < dist[v.node][u.hull - v.hull]) {
        dist[v.node][u.hull - v.hull] = u.time + v.time;
        pq.push({v.node, u.time + v.time, u.hull - v.hull});
      }
    }
  }

  cout << -1 << endl;
  return 0;
}