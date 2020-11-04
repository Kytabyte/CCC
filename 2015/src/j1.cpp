#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, d;
  cin >> m >> d;
  if (m == 2 && d == 18) {
    cout << "Special" << endl;
  } else if (m > 2 || m == 2 && d > 18) {
    cout << "After" << endl;
  } else {
    cout << "Before" << endl;
  }
  
  return 0;
}