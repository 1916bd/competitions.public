#include <tbb/parallel_for_each.h>

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <stack>
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
  int N, K, W;
  vector<int> L, H;
  int A_l, B_l, C_l, D_l;
  int A_h, B_h, C_h, D_h;

  // output
  int perimeter;
};

vector<Input> case_data;

void process_case(Input& in) {
  // Generate P
  for (int i = in.K; i < in.N; ++i)
    in.L[i] = ((LL)in.A_l * in.L[i - 2] + (LL)in.B_l * in.L[i - 1] + in.C_l) %
                  in.D_l +
              1;
  // Generate Q
  for (int i = in.K; i < in.N; ++i)
    in.H[i] = ((LL)in.A_h * in.H[i - 2] + (LL)in.B_h * in.H[i - 1] + in.C_h) %
                  in.D_h +
              1;

  deque<pair<int, int>> s;
  int p = 0, agg_p = 1;
  for (int i = 0; i < in.N; ++i) {
    while (!s.empty() && s.front().first + in.W < in.L[i]) s.pop_front();
    if (s.empty()) {
      inc_mod(p, 2 * in.W);
      inc_mod(p, 2 * in.H[i]);
    } else {
      int vdelta = 0;
      while (!s.empty() && s.back().second <= in.H[i]) {
        vdelta = 2 * (in.H[i] - s.back().second);
        s.pop_back();
      }
      if (!s.empty() && s.back().second >= in.H[i]) vdelta = 0;
      inc_mod(p, vdelta);
      inc_mod(p, 2 * (in.L[i] - in.L[i - 1]));
    }
    s.emplace_back(in.L[i], in.H[i]);
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
    scanf("%d %d %d", &in.N, &in.K, &in.W);
    in.L.resize(in.N);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.L[i]);
    scanf("%d %d %d %d", &in.A_l, &in.B_l, &in.C_l, &in.D_l);
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
