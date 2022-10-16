#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1'000'000;
const int MAX_A = 26;

int cur_sum[MAX_A][MAX_A];
int best_sum[MAX_A][MAX_A];
int previous_sum[MAX_A][MAX_A];
int min_prefix[MAX_A][MAX_A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;

  cin >> n;
  cin >> s;

  // tab[a][b] -> a - min, b - max
  for (int i = 0; i < MAX_A; ++i) {
    for (int j = 0; j < MAX_A; ++j) {
      min_prefix[i][j] = 2 * MAX_N;
    }
  }

  for (int i = 0; i < n; ++i) {
    int cc = s[i] - 'a';
    // consider as max
    for (int c = 0; c < MAX_A; ++c) {
      ++cur_sum[c][cc];
      best_sum[c][cc] =
          max(best_sum[c][cc], cur_sum[c][cc] - min_prefix[c][cc]);
    }
    // consider as min
    for (int c = 0; c < MAX_A; ++c) {
      --cur_sum[cc][c];
      min_prefix[cc][c] = min(min_prefix[cc][c], previous_sum[cc][c]);
      previous_sum[cc][c] = cur_sum[cc][c];
      best_sum[cc][c] =
          max(best_sum[cc][c], cur_sum[cc][c] - min_prefix[cc][c]);
    }
  }
  int res = 0;
  for (int i = 0; i < MAX_A; ++i) {
    for (int j = 0; j < MAX_A; ++j) {
      res = max(res, best_sum[i][j]);
    }
  }
  cout << res << endl;
  return 0;
}
