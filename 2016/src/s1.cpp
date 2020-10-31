#include <bits/stdc++.h>

using namespace std;

int cnt[26] = {0};

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  for (char ch : s1) {
    cnt[ch - 'a']++;
  }

  for (char ch : s2) {
    if (ch == '*') {
      continue;
    }
    if (cnt[ch - 'a'] == 0) {
      cout << "N" << endl;
      return 0;
    }
    cnt[ch - 'a']--;
  }
  cout << "A" << endl;

  return 0;
}