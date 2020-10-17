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

int digits[4];

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &digits[i]);
  }

  if (digits[0] != 8 && digits[0] != 9 || digits[3] != 8 && digits[3] != 9 || digits[1] != digits[2]) {
    cout << "answer" << endl;
  } else {
    cout << "ignore" << endl;
  }

  return 0;
}