#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

using LL = long long;
const LL SENTINEL = -9187201950435737472LL;
const LL INF = SENTINEL + 1;
const int MAX_N = 201;
const int MAX_B = 61;

int B[MAX_B];
LL pref[MAX_N];
LL mem[MAX_B][2][MAX_N][MAX_N];

LL f(int bit_no, int is_lower, int l, int r) {
  LL& res = mem[bit_no + 1][is_lower][l][r];
  if (res != SENTINEL) return res;
  if (bit_no < 0) return res = r - l <= 1 ? 0 : INF;
  res = f(bit_no - 1, is_lower || B[bit_no], l, r);
  if (B[bit_no] || is_lower) {
    FOR(m, l, r - 1) {
      LL s0 = f(bit_no - 1, 1, l, m);
      if (s0 == INF) continue;
      LL s1 = f(bit_no - 1, is_lower, m, r);
      if (s1 == INF) continue;
      res = max(res, s0 + s1 + pref[r] - pref[m]);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  LL m, a[MAX_N];
  cin >> n >> m;
  REP(i, n) cin >> a[i];
  pref[0] = 0;
  REP(i, n) pref[i + 1] = pref[i] + a[i];
  REP(i, MAX_B) B[i] = (m >> i) & 1;
  memset(mem, 0x80, sizeof(mem));
  cout << f(MAX_B - 2, 0, 0, n) << endl;
  return 0;
}
