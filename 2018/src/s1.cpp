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

const int INF = 2e9;

int main() {
  int N;
  scanf("%d", &N);

  vector<double> v(N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &v[i]);
  }
  sort(v.begin(), v.end());

  double ans = INF;
  for (int i = 1; i < N - 1; i++) {
    ans = min(ans, (v[i] - v[i-1]) / 2 + (v[i+1] - v[i]) / 2);
  }
  
  cout << fixed << setprecision(1) << ans << endl;

  return 0;
}