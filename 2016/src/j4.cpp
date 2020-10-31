#include <bits/stdc++.h>

using namespace std;

const int TOTAL = 120;

int main() {
  int h, m;
  string s;
  cin >> s;
  h = stoi(s.substr(0, 2));
  m = stoi(s.substr(3, 2));
  if (7 <= h && h < 10 || 15 <= h && h < 19) {
    int half;
    if (7 <= h && h < 10) {
      half = ((10 - h) * 60 - m) / 2;
    } else {
      half = ((19 - h) * 60 - m) / 2;
    }
    int rem = TOTAL - half;
    m = rem % 60;
    if (7 <= h && h < 10) {
      h = 10 + (rem / 60);
    } else {
      h = 19 + (rem / 60);
    }
    h %= 24;
  } else if (5 <= h && h < 7) {
    int rem = (7 - h) * 60 - m;
    int twice = TOTAL - rem;
    if (twice < 90) {
      twice *= 2;
      h = 7 + (twice / 60);
      m = twice % 60;
    } else {
      rem = twice - 90;
      h = 10 + (rem / 60);
      m = rem % 60;
    }
  } else if (13 <= h && h < 15) {
    int rem = (15 - h) * 60 - m;
    int twice = (TOTAL - rem) * 2;
    h = 15 + (twice / 60);
    m = twice % 60;
  } else {
    h = (h + 2) % 24;
  }
  printf("%02d:%02d\n", h, m);
  return 0;
}