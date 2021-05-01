#include <bits/stdc++.h>

using namespace std;

/** Analysis
 * 
 * if we want to satisfy all the gcd conditions,
 * the ith number ans[i] should be the lcm of all conditions including this index
 * 
 * Invalid case: Just to find the lcm of each index i, and check if each condition is satisfied.
 * 
 * To find lcm of each index: use a difference array to track all the 16 possbilities at each index i.
 * For each index i, find the lcm_i.
 * 
 * To check the gcd of each condition, we need to query the gcd of arbitary range.
 * Segment tree is the best data structure for this task. 
 */

const int Mxn = 150005, Mxm = 150005, Mxz = 21;
int diff[Mxn][Mxz], ans[Mxn], st[Mxn*4];
array<int, 3> a[Mxm];

void build(int i = 1, int tl = 1, int tr = Mxn) {
    if (tl == tr) {
        st[i] = ans[tl];
    } else {
        int mid = tl + (tr - tl) / 2;
        build(i*2, tl, mid);
        build(i*2+1, mid+1, tr);
        st[i] = __gcd(st[i*2], st[i*2+1]);
    }
}

int query(int l, int r, int i = 1, int tl = 1, int tr = Mxn) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return st[i];
    }
    int mid = tl + (tr - tl) / 2;
    return __gcd(query(l, min(r, mid), i*2, tl, mid), 
                query(max(l, mid+1), r, i*2+1, mid+1, tr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(diff, 0, sizeof(diff)); // 2d difference array
  memset(st, 0, sizeof(st));
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z; cin >> x >> y >> z;
    diff[x][z]++;
    diff[y+1][z]--;
    a[i] = {x, y, z};
  }

  int d[Mxn];
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; i++) {
    int lcm = 1;
    for (int j = 1; j <= 16; j++) {
      d[j] += diff[i][j];
      if (d[j] > 0) {
        lcm = lcm * j / __gcd(lcm, j);
      }
    }
    ans[i] = lcm; // the ith element should be the lcm of all needed number
  }
  
  build();

  for (int i = 0; i < m; i++) {
    tie(x, y, z) = a[i]
    if (query(x, y) != z) {
      cout << "Impossible\n";
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}