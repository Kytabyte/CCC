#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;

  stack<int> st;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m == 0) {
      st.pop();
    } else {
      st.push(m);
    }
  }
  
  int ans = 0;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  cout << ans << endl;
    
  return 0;
}