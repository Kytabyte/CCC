#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, k;
  cin >> N >> k;

  int sum = N;
  for (int i = 0; i < k; i++) {
    N *= 10;
    sum += N;
  }
  cout << sum << endl;
  
  return 0;
}