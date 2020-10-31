#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
int nums[MAXN], ans[MAXN];

int N;
ll T;
string s;

void op(ll unit) {
  for (ll i = 0; i < N; i++) {
    int pre = ((i - unit) % N + N) % N;
    int post = (i + unit) % N;
    ans[i] = nums[pre] ^ nums[post];
  }
  for (int i = 0; i < N; i++) {
    nums[i] = ans[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> T >> s;
  for (int i = 0; i < N; i++) {
    nums[i] = (s[i] - '0');
  }

  for (int i = 63; i >= 0; i--) {
    if (T & (1LL << i)) {
      op(1LL << i);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}