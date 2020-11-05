// BOILERPLATE_BEGIN
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
// BOILERPLATE_END
#define TEST_CASE "tests/wie5"

const int MAX_N = 3000;

bool Process1d(vector<int>& res, vector<pair<pair<int, int>, int>>& v) {
  int n = v.size();
  res.resize(n);
  sort(v.begin(), v.end());
  bitset<MAX_N + 2> avail;
  avail.set();
  REP(i, n) {
    auto p = v[i].first;
    auto it = avail._Find_next(p.second - 1);
    if (it > p.first) return false;
    res[v[i].second] = it;
    avail.set(it, false);
  }
  return true;
}

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
  int n, a, b, c, d;
  vector<pair<pair<int, int>, int>> rows, cols;
  vector<int> res[2];
  cin >> n;
  rows.reserve(n);
  cols.reserve(n);
  REP(i, n) {
    cin >> a >> b >> c >> d;
    rows.emplace_back(make_pair(c, a), i);
    cols.emplace_back(make_pair(d, b), i);
  }
  if (Process1d(res[0], rows) && Process1d(res[1], cols)) {
    REP(i, n) cout << res[0][i] << " " << res[1][i] << endl;
  } else
    cout << "NIE" << endl;
  return 0;
}
