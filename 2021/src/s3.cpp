#include <bits/stdc++.h>

using namespace std;

/** Analysis
 * 
 * Observation:
 * Define the total distance of all points to any given point pos is dist(pos),
 * then we can observe that dist(x) is a "valley" array when x is increasing.
 * 
 * That is dist(0) <= dist(1) <= ... dist(mid-1) <= dist(mid) >= dist(mid+1) >= ... >= dist(inf)
 * So there is a point in the middle that dist(mid) is our target number.
 * 
 * Thus, we can introduce binary search to solve this problem.
 * 
 */

typedef long long ll;

const int Mxn = 200005;
int p[Mxn], w[Mxn], d[Mxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i] >> w[i] >> d[i];
  }

  // if pos is the answer, what is the total dist of all points this pos
  auto dist = [&](int pos) {
    ll ans = 0;

    for (int i = 0; i < n; i++) {
      if (p[i] > pos + d[i]) {
        ans += (ll)w[i] * (p[i] - (pos + d[i]));
      } else if (p[i] < pos - d[i]) {
        ans += (ll)w[i] * (pos - d[i] - p[i]);
      }
    }

    return ans;
  };

  // the dist function should be in a decrease-then-increase shape
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int mid = (lo+hi) / 2;

    ll cur = dist(mid), nxt = dist(mid+1);
    
    if (cur > nxt) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  
  cout << dist(lo) << '\n';

  return 0;
}