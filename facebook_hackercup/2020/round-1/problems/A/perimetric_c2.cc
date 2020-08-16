#include <tbb/parallel_for_each.h>

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;

const int MOD = 1'000'000'007;

void inc_mod(int& a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

struct Input {
  int cs, N, K;
  vector<int> L, H, W;
  int A_l, B_l, C_l, D_l;
  int A_h, B_h, C_h, D_h;
  int A_w, B_w, C_w, D_w;

  // output
  int perimeter;
};

vector<Input> case_data;

void process_case(Input& in) {
  // Generate L
  for (int i = in.K; i < in.N; ++i)
    in.L[i] = ((LL)in.A_l * in.L[i - 2] + (LL)in.B_l * in.L[i - 1] + in.C_l) %
                  in.D_l +
              1;
  // Generate W
  for (int i = in.K; i < in.N; ++i)
    in.W[i] = ((LL)in.A_w * in.W[i - 2] + (LL)in.B_w * in.W[i - 1] + in.C_w) %
                  in.D_w +
              1;
  // Generate H
  for (int i = in.K; i < in.N; ++i)
    in.H[i] = ((LL)in.A_h * in.H[i - 2] + (LL)in.B_h * in.H[i - 1] + in.C_h) %
                  in.D_h +
              1;

  int p = 0, agg_p = 1;
  map<int, int> m;  // disjoint r -> l
  m[-1] = -2;
  for (int i = 0; i < in.N; ++i) {
    int l = in.L[i], r = in.L[i] + in.W[i], delta_w = in.W[i],
        intersections = 0;
    auto it = m.lower_bound(l);

    while (it != m.end() && it->second <= r) {
      // intersection with [l, r]
      int nl = max(l, it->second), nr = min(r, it->first);

      delta_w -= nr - nl;
      ++intersections;

      l = min(l, it->second);
      r = max(r, it->first);

      m.erase(it++);
    }
    m[r] = l;
    inc_mod(p, 2LL * (MOD + 1 - intersections) * in.H[i] % MOD);
    inc_mod(p, 2LL * delta_w);
    agg_p = (LL)agg_p * p % MOD;
  }

  in.perimeter = agg_p;
}

int main() {
  int T;
  scanf("%d", &T);
  case_data.resize(T);
  for (int cs = 0; cs < T; ++cs) {
    auto& in = case_data[cs];
    in.cs = cs;
    scanf("%d %d", &in.N, &in.K);
    in.L.resize(in.N);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.L[i]);
    scanf("%d %d %d %d", &in.A_l, &in.B_l, &in.C_l, &in.D_l);
    in.W.resize(in.N);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.W[i]);
    scanf("%d %d %d %d", &in.A_w, &in.B_w, &in.C_w, &in.D_w);
    in.H.resize(in.N);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.H[i]);
    scanf("%d %d %d %d", &in.A_h, &in.B_h, &in.C_h, &in.D_h);
  }
  tbb::parallel_for_each(&case_data[0], &case_data[0] + T, process_case);
  for (int cs = 0; cs < T; ++cs) {
    printf("Case #%d: %d\n", cs + 1, case_data[cs].perimeter);
  }
  return 0;
}
