#include <bits/stdc++.h>

using namespace std;

/**
 * Marks: 15/15
 */

int dist[5] = {0};

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &dist[i+1]);
    dist[i+1] += dist[i];
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << abs(dist[j] - dist[i]);
      if (j == 4) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  }

  return 0;
}