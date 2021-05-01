#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string prev_instruction;

  while (n != 99999) {
    int first = n/1000, num = n%1000;
    string instruction;

    int sum = first/10 + first%10;
    if (sum % 2) {
      instruction = "left ";
    } else if (sum == 0) {
      instruction = prev_instruction;
    } else {
      instruction = "right ";
    }
    
    cout << instruction << num << '\n';
    prev_instruction = instruction;

    cin >> n;
  }
  
  return 0;
}