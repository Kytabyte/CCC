#include <bits/stdc++.h>

using namespace std;

int main() {
  int win = 0;
  char c;
  for (int i = 0; i < 6; i++) {
    cin >> c;
    if (c == 'W') 
      win++;
  }
  if (win >= 5) cout << 1 << endl;
  else if (win >= 3) cout << 2 << endl;
  else if (win >= 1) cout << 3 << endl;
  else cout << -1 << endl;
  return 0;
}