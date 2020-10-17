# include <bits/stdc++.h>

using namespace std;

int main() {
  string x, y;
  cin >> x >> y;

  if (x.size() < y.size()) {
    cout << "no" << endl;
  } else {
    int l = y.size();
    string z = y + y;
    for (int i = 0; i < x.size() - l; i++) {
      string cand = x.substr(i, l);
      if (z.find(cand) != string::npos) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }

  cout << "no" << endl;

  return 0;
}

