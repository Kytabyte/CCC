#include <bits/stdc++.h>

using namespace std;

int main() {
  int sx, sy, ex, ey, t;
  cin >> sx >> sy >> ex >> ey >> t;

  int dist = abs(sx - ex) + abs(sy - ey);
  if (dist > t) {
    cout << 'N' << endl;
  } else {
    cout << (dist % 2 == t % 2 ? 'Y' : 'N') << endl;
  }

  return 0;
}