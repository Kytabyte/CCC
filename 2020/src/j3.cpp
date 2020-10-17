# include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int x_min=101, x_max=-1, y_min=101, y_max=-1;
  string coord;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> coord;
    auto pos = coord.find(",");
    x = stoi(coord.substr(0, pos));
    y = stoi(coord.substr(pos+1));
    x_min = min(x_min, x);
    x_max = max(x_max, x);
    y_min = min(y_min, y);
    y_max = max(y_max, y);
  }

  cout << (x_min-1) << "," << (y_min-1) << endl;
  cout << (x_max+1) << "," << (y_max+1) << endl;
  return 0;
}
