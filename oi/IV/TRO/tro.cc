// BOILERPLATE_BEGIN
/**
 *
 * Trójkąty jednobarwne
 * 
 * Status: AC
 * Competition: Olimpiada Informatyczna IV
 * Link: https://szkopul.edu.pl/problemset/problem/UU2Uj-barjiONnRxd9aEVoDj/site/?key=statement
 * Tags: #math #set-complement
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

const int MAX_N = 1000;
int out[MAX_N];

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
  int n, m, x, y, res = 0;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    ++out[x];
    ++out[y];
  }
  for (int i = 1; i <= n; ++i) {
    // cerr << NAME(out[i]) << endl;
    res += out[i] * (n - 1 - out[i]);
  }
  cout << n * (n - 1) * (n - 2) / 6 - res / 2 << endl;
  return 0;
}
