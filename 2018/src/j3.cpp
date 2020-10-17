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

int dist[5] = {0};
// int ans[5][5] = {0};

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &dist[i+1]);
    dist[i+1] += dist[i];
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << abs(dist[j] - dist[i]);
      if (j == 4) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  }

  return 0;
}