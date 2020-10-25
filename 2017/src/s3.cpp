#include <bits/stdc++.h>

using namespace std;

const int MINL = 1, MAXL = 2000;
int length[MAXL * 2 + 5] = {0};

int main() {
  int n, l;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> l;
    length[l]++;
  }

  int maxl=0, cnt=0, curl;
  for (int sum = MINL * 2; sum <= MAXL * 2; sum++) {
    curl = 0;
    for (int h1 = MINL, h2 = sum - h1; h1 <= h2; h1++, h2--) {
      if (h1 == h2) {
        curl += length[h1] / 2;
      } else {
        curl += min(length[h1], length[h2]) ;
      }
    }
    if (curl > maxl) {
      maxl = curl;
      cnt = 1;
    } else if (curl == maxl) {
      cnt++;
    }
  }

  cout << maxl << ' ' << cnt << endl;

  return 0;
}
