#include <bits/stdc++.h>

using namespace std;

int row[4] = {0}, col[4] = {0};

int main() {
  int n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> n;
      row[i] += n;
      col[j] += n;
    }
  } 

  bool magic = true;
  for (int i = 0; i < 4; i++) {
    if (row[i] != row[0] || col[i] != col[0]) {
      magic = false;
    }
  }
  cout << (magic ? "" : "not ") << "magic" << endl;
  return 0;
}