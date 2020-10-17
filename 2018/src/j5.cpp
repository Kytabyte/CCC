#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) cerr << " [" << #__VA_ARGS__  << ": " << (__VA_ARGS__) << "] "
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> p) {
  return s << " (" << p.first << "," << p.second << ") ";
}
template<typename T> ostream& operator<<(ostream& s, vector<T> v) {
  s << "size: " << v.size() << " {";
  for (T& t : v) {
    s << t << " ";
  }
  s << "} ";
  return s;
}
template<typename T> ostream& operator<<(ostream& s, vector<vector<T>> m) {
  s << "shape: " << m.size() << 'x' << m[0].size() << endl;
  for (vector<T>& r : m) {
    for (T& t : r) {
      cout << t << ' ';
    }
    cout << endl;
  }
  return s;
}

int main() {
  int N;
  scanf("%d", &N);

  vector<bool> reach(N, 0);
  reach[0] = true;

  vector<vector<int>> graph(N);
  int n;
  for (int i = 0; i < N; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      int m;
      scanf("%d", &m);
      reach[m-1] = true;
      graph[i].push_back(m-1);
    }
  }


  // reachable
  bool reachable = true;
  for (int i = 0; i < N; i++) {
    if (!reach[i]) {
      reachable = false;
      break;
    }
  }

  cout << (reachable ? "Y" : "N") << endl;

  // shortest path
  queue<int> qu;
  vector<int> seen(N, false);
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