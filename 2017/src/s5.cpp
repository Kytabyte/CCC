#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE */

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

typedef long long ll;
typedef pair<int, int> pii;

/** END OF TEMPLATE */

/** CODE STARTS HERE */
struct node {
  int sum;
  unordered_map<int, int> cache;
}

int MAXN = 150000 + 5;
int M, N, Q, line[MAXN], people[MAXN];
node st[MAX * 2] = {0};

int query(int l, int r) {

}

void update(int l, int r, int line) {

}

int main() {

  return 0;
}