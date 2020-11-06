// BOILERPLATE_BEGIN
/**
 *
 * Jedynki i zera 2
 * 
 * Status: AC
 * Competition: Olimpiada Informatyczna II
 * Link: https://szkopul.edu.pl/problemset/problem/zMktwkCSdzEzUp3IvXmLzMzi/site/?key=statement
 * Tags: #bfs
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
// BOILERPLATE_END
#define TEST_CASE "tests/0"

const int MAX_N = 1'000'000;
int mem[MAX_N];

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
  int K, x;
  cin >> K;
  REP(cs, K) {
    cin >> x;
    if (x == 1) {
      cout << 1 << endl;
      continue;
    }

    memset(mem, 0xFF, x * sizeof(mem[0]));
    queue<int> q;

    auto enqueue = [&](int r, int p) {
      if (mem[r] >= 0) return;
      mem[r] = p;
      q.emplace(r);
    };

    enqueue(1, 0);
    while (!q.empty()) {
      auto r = q.front();
      q.pop();
      if (r == 0) {
        // restore
        vector<int> v;
        int cur = 0;
        do {
          int pre = mem[cur];
          v.emplace_back((pre * 10) % x == cur ? 0 : 1);
          cur = pre;
        } while (cur != 0);
        reverse(v.begin(), v.end());
        for (auto t : v) cout << t;
        cout << endl;
        break;
      }
      REP(i, 2) enqueue((10 * r + i) % x, r);
    }
  }
  return 0;
}
