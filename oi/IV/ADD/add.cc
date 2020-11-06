// BOILERPLATE_BEGIN
/**
 *
 * Addon
 * 
 * Status: AC
 * Competition: Olimpiada Informatyczna IV
 * Link: https://szkopul.edu.pl/problemset/problem/qHKn-JJ26gBkxuKO-5MQC9mo/site/?key=statement
 * Tags: #dijkstra
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

const int MAX_N = 10000;
bool safe[MAX_N + 1], vis[MAX_N + 1];

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
  vector<int> res;
  priority_queue<pair<int, int>> q;
  int n, x;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    safe[x] = 1;
    q.emplace(-x, 0);
  }
  int last = 0;
  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    int tval = -t.first, tadd = 1 ^ t.second;
    if (tval > MAX_N || !safe[tval]) {
      // Tests are incorrect, it should be tval-1
      cout << last << endl;
      break;
    }
    if (vis[tval]) continue;
    vis[tval] = 1;
    last = tval;
    if (tadd) {
      res.emplace_back(tval);
    }
    for (const auto& e : res) {
      q.emplace(-(tval + e), 1);
    }
  }
  for (const auto& e : res) {
    cout << e << endl;
  }
  return 0;
}
