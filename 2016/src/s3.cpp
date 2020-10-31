#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
bool ispho[MAXN];
int max_diam = -1;

int pho_diameter(int u, int p) { 
  int max1 = -1, max2 = -1; 
  for (int v : graph[u]) {
    if (v != p) {
      int retmax = pho_diameter(v, u);
      if (retmax > max2) {
        max2 = retmax;
      }
      if (max2 > max1) {
        swap(max1, max2);
      }

      if (ispho[v]) {
        ispho[u] = true; // make all pho resturants connected
      }
    }
  }

  int max_depth = -1, diam = -1;
  if (max1 >= 0 && max2 >= 0 || ispho[u]) {
    diam = max1 + max2 + 2;
    max_depth = 1 + max(max1, max2);
  }
  if (diam > max_diam) {
    max_diam = diam;
  }

  return max_depth;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int start, N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> start;
    ispho[start] = true;
  }

  int u, v;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  pho_diameter(start, -1);

  // all pho resturants are connected. 
  // Regard it as a new graph.
  // `n` resturants are connected with `n-1` edges
  // each edge will be passed twice except for the diamemter of this new graph,
  // because we can pass this diameter, and visited other restaurants in the process 
  // when we are at the closest point to those restaurants.
  int pho = accumulate(ispho, ispho + N, 0);
  int ans = 2 * (pho - 1) - max_diam;
  cout << ans << endl;

  return 0;
}