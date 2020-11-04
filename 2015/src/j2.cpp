#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string happy = ":-)", sad = ":-(";
  int n1 = 0, n2 = 0;

  string s;
  getline(cin, s);
  int n = s.size();
  for (int i = 0; i <= n - 3; i++) {
    if (s.substr(i, 3) == happy) {
      n1++;
    } else if (s.substr(i, 3) == sad) {
      n2++;
    }
  }

  if (n1 == 0 && n2 == 0) {
    cout << "none" << endl;
  } else if (n1 == n2) {
    cout << "unsure" << endl;
  } else if (n1 > n2) {
    cout << "happy" << endl;
  } else {
    cout << "sad" << endl;
  }
  
  
  return 0;
}