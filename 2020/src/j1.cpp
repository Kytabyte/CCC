# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int main() {
  int s, m, l;
  cin >> s >> m >> l;

  int score = s + 2 * m + 3 * l;
  if (score >= 10) {
    cout << "happy" << endl;
  } else {
    cout << "sad" << endl;
  }

  return 0;
}

