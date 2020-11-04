#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string vowels = "aeiou";
  string s;
  cin >> s;

  string ans;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    ans += s[i];
    if (vowels.find(s[i]) == string::npos) {
      int d = 30, j;
      for (int k = 0; k < 5; k++) {
        if (abs(vowels[k] - s[i]) < d) {
          d = abs(vowels[k] - s[i]);
          j = k;
        }
      }
      ans += vowels[j];
      if (s[i] == 'z') {
        ans += 'z';
      } else if (vowels.find(s[i] + 1) == string::npos) {
        ans += s[i] + 1;
      } else {
        ans += s[i] + 2;
      }
    }
  }
  cout << ans << endl;

  return 0;
}