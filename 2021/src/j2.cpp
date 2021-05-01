#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string winner;
  int win_amount = 0;

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    int amount;
    cin >> name >> amount;
    if (amount > win_amount) {
      winner = name, win_amount = amount;
    }
  }
  
  cout << winner << '\n';
  
  return 0;
}