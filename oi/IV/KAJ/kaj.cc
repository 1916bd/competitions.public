// BOILERPLATE_BEGIN
/**
 *
 * Kajaki
 * 
 * Status: AC
 * Competition: Olimpiada Informatyczna IV
 * Link: https://szkopul.edu.pl/problemset/problem/qcEpw4SfiiE9VBmBrUz2LgW3/site/?key=statement
 * Tags: #greedy
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define NAME(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// BOILERPLATE_END
#define TEST_CASE "tests/0"

const int MAX_W = 200;
int w[MAX_W + 1];

int main() {
  // BOILERPLATE_BEGIN
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen(TEST_CASE ".in", "r", stdin);
  freopen(TEST_CASE ".out", "w", stdout);
#endif
  // BOILERPLATE_END
  int W, n, x;
  cin >> W >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++w[x];
  }
  int res = 0, l = 0, r = W;
  for (;;) {
    while (l < r && !w[l]) ++l;
    while (l < r && !w[r]) --r;
    if (l > r) break;
    if (l == r) {
      if (2 * l <= W)
        res += (w[l] + 1) / 2;
      else
        res += w[l];
      break;
    }
    if (l + r <= W) {
      if (w[l] < w[r]) {
        res += w[l];
        w[r] -= w[l++];
      } else {
        res += w[r];
        w[l] -= w[r--];
      }
    } else {
      res += w[r--];
    }
  }
  cout << res << endl;
  return 0;
}
