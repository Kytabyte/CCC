#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) cerr << "[" << #__VA_ARGS__  << ": " << (__VA_ARGS__) << "] "
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
    int N, K;
    cin >> N >> K;

    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    

    return 0;
}