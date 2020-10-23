#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

void dfs(vector<vector<int>>& graph, int node, vector<bool>& seen) {
  for (int nbr : graph[node]) {
    if (!seen[nbr]) {
      seen[nbr] = true;
      dfs(graph, nbr, seen);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);

  vector<vector<int>> graph(N);
  int n, m;
  for (int i = 0; i < N; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      scanf("%d", &m);
      graph[i].push_back(m-1);
    }
  }

  vector<bool> seen(N, 0);
  seen[0] = 1;
  dfs(graph, 0, seen);

  // reachable
  bool reachable = true;
  for (int i = 0; i < N; i++) {
    if (!seen[i]) {
      reachable = false;
      break;
    }
  }
  cout << (reachable ? 'Y' : 'N') << endl;

  // shortest path, bfs
  queue<int> qu;
  fill(seen.begin(), seen.end(), false);
  qu.push(0); seen[0] = true;
  int step = 1;

  while (!qu.empty()) {
    int size = qu.size();
    bool found = false;
    for (int i = 0; i < size; i++) {
      int node = qu.front(); qu.pop();
      if (graph[node].empty()) {
        found = true;
        break;
      }

      for (int nbr : graph[node]) {
        if (!seen[nbr]) {
          seen[nbr] = true;
          qu.push(nbr);
        }
      }
    }

    if (found) {
      cout << step << endl;
      break;
    }
    step++;
  }


  return 0;
}