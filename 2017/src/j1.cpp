#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (x * y > 0) 
    cout << (x > 0 ? 1 : 3) << endl;
  else 
    cout << (x > 0 ? 4 : 2) << endl;

  return 0;
}