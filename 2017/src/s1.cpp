#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  vector<int> swift, sema;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    swift.push_back(v);
  }
  for (int i = 0; i < n; i++) {
    int v; 
    cin >> v;
    sema.push_back(v);
  }

  int k = 0, sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 += swift[i];
    sum2 += sema[i];
    if (sum1 == sum2) {
      k = i + 1;
    }
  }

  cout << k << endl;
  return 0;
}