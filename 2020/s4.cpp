# include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int N;
string S;
char seats[3] = {'A', 'B', 'C'};
vector<int> presum[3];

int solve() {
  int Na = presum[0].back(), Nb = presum[1].back();
  int Nab = Na + Nb;

  int ans = 1e9;
  for (int i = 0; i <= N - Nab; i++) {
    int na = presum[0][i + Nab] - presum[0][i];
    int nb = presum[1][i + Nab] - presum[1][i];
    int nc = presum[2][i + Nab] - presum[2][i];

    int da = Na - na, db = Nb - nb;

    int fa = presum[0][i + Na] - presum[0][i];
    int fca = presum[2][i + Na] - presum[2][i];
    int fb = presum[1][i + Nb] - presum[1][i];
    int fcb =  presum[2][i + Nb] - presum[2][i];

    int cur = nc + min(Na - (fa + min(da, fca)), Nb - (fb + min(db, fcb)));

    ans = min(ans, cur);
  }

  return ans;
}

void doswap(int i, int j) {
  for (int k = 0; k < N; k++) {
    if (S[k] == seats[i]) {
      S[k] = seats[j];
    } else if (S[k] == seats[j]) {
      S[k] = seats[i];
    }
  }
  swap(seats[i], seats[j]);
  swap(presum[i], presum[j]);
}

int main() {
  cin >> S;
  N = S.size();

  for (int i = 0; i < 3; i++) {
    presum[i] = vector<int>(N+1, 0);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      presum[j][i+1] = presum[j][i] + (S[i] - 'A' == j);
    }
  }

  int ans = 1e9;
  ans = min(ans, solve()); // ABC
  doswap(1, 2);
  ans = min(ans, solve()); // ACB
  doswap(0, 1);
  ans = min(ans, solve()); // CAB
  doswap(1, 2);
  ans = min(ans, solve()); // CBA
  doswap(0, 1);
  ans = min(ans, solve()); // BCA
  doswap(1, 2);
  ans = min(ans, solve()); // BAC
  cout << ans << endl;

  return 0;
}

