# include <bits/stdc++.h>

using namespace std;

// const int M = 500001;

int main() {
  int N;
  unordered_map<int, int> last, count;
  unordered_map<int, double> probs;
  vector<int> B;
  
  cin >> N;
  B = vector<int>(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    last[B[i]] = i;
    // count[B[i]]++;
  }

  int n = B.size(), coach = B[0], josh = B.back();
  int m = last.size();
  if (coach == josh) {
    cout << 1 << endl;
  } else {
    probs[coach] = 1;
    probs[josh] = 0;
    count[coach] = 1;
    for (int i = n-1; i >= 1; i--) {
      if (B[i] != coach && B[i] != josh && last[B[i]] == i) {
        double prob = 0;
        for (auto& p : count) {
          prob += p.second * 1.0 / (n - i) * probs[p.first];
        }
        probs[B[i]] = prob;
      }
      count[B[i]]++;
    }

    double ans = 0;
    for (auto& p : probs) {
      ans += p.second * count[p.first] / n;
    }


    cout << fixed << setprecision(9) << ans << endl;
  }

  return 0;
}