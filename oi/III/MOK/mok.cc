// BOILERPLATE_BEGIN
/**
 *
 * Mokra robota

 * Status: AC
 * Competition: Olimpiada Informatyczna III
 * Link: https://szkopul.edu.pl/problemset/problem/vObl4Sutc8ViCjq0_eNse2uy/site/?key=statement
 * Tags: #bfs
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
// BOILERPLATE_END
#define TEST_CASE "tests/0"

int n;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int encode(int* a) {
  int res = 0;
  REP(i, n) {
    res <<= 6;
    res += a[i];
  }
  return res;
}

void decode(int t, int* a) {
  for (int i = n - 1; i >= 0; --i) {
    a[i] = t & 63;
    t >>= 6;
  }
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
  int g = 0, cap[4], out[4], aux[4], infeasible = 0, end;
  bitset<1 << 24> mem;
  queue<pair<int, int>> q;
  cin >> n;
  REP(i, n) {
    cin >> cap[i];
    g = gcd(g, cap[i]);
  }
  REP(i, n) {
    cin >> out[i];
    infeasible += out[i] % g;
  }
  if (infeasible) {
    cout << "NIE" << endl;
    return 0;
  }
  end = encode(out);

  auto ins = [&](int v, int cost) {
    if (mem[v]) return;
    mem[v] = 1;
    q.emplace(v, cost);
  };

  ins(encode(cap), 0);
  while (!q.empty()) {
    auto el = q.front();
    q.pop();
    if (el.first == end) {
      cout << el.second << endl;
      return 0;
    }
    decode(el.first, aux);
    // fill j from i
    REP(i, n) {
      if (aux[i] == 0) continue;
      REP(j, n) {
        if (i == j || aux[j] == cap[j]) continue;
        int diff = min(aux[i], cap[j] - aux[j]);
        aux[i] -= diff;
        aux[j] += diff;
        ins(encode(aux), el.second + 1);
        aux[i] += diff;
        aux[j] -= diff;
      }
    }
    // dump i
    REP(i, n) {
      if (!aux[i]) continue;
      int t = aux[i];
      aux[i] = 0;
      ins(encode(aux), el.second + 1);
      aux[i] = t;
    }
  }
  return 0;
}
