#include <tbb/parallel_for_each.h>

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

struct Input {
  int N, M, K, S;
  vector<int> P, Q;
  int A_p, B_p, C_p, D_p;
  int A_q, B_q, C_q, D_q;

  // output
  LL seconds;
};

vector<Input> case_data;

bool can_assign(LL max_per_worker, const vector<int>& workers,
                const vector<int>& logs, int S) {
  int log_idx = 0, n = workers.size(), m = logs.size();
  for (int wi = 0; wi < n; ++wi) {
    if (log_idx >= m) return true;
    int no = 0;
    while (log_idx + no < m) {
      LL new_cost = (LL)(no + 1) * S + (logs[log_idx + no] - logs[log_idx]) +
                    min(abs(workers[wi] - logs[log_idx]),
                        abs(workers[wi] - logs[log_idx + no]));
      if (new_cost <= max_per_worker)
        ++no;
      else
        break;
    }
    log_idx += no;
  }
  return log_idx >= m;
}

void process_case(Input& in) {
  // Generate P
  for (int i = in.K; i < in.N; ++i)
    in.P[i] = ((LL)in.A_p * in.P[i - 2] + (LL)in.B_p * in.P[i - 1] + in.C_p) %
                  in.D_p +
              1;
  sort(in.P.begin(), in.P.end());
  // Generate Q
  for (int i = in.K; i < in.M; ++i)
    in.Q[i] = ((LL)in.A_q * in.Q[i - 2] + (LL)in.B_q * in.Q[i - 1] + in.C_q) %
                  in.D_q +
              1;
  sort(in.Q.begin(), in.Q.end());
  // Get upper bound for binary search
  LL lo = 0, mid;
  LL hi = (LL)in.M * in.S + (in.Q[in.M - 1] - in.Q[0]) +
          min(abs(in.P[0] - in.Q[0]), abs(in.P[0] - in.Q[in.M - 1]));
  // Binary search
  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    if (can_assign(mid, in.P, in.Q, in.S))
      hi = mid;
    else
      lo = mid + 1;
  }
  assert(can_assign(hi, in.P, in.Q, in.S));
  in.seconds = hi;
}

int main() {
  int T;
  scanf("%d", &T);
  case_data.resize(T);
  for (int cs = 0; cs < T; ++cs) {
    auto& in = case_data[cs];
    scanf("%d %d %d %d", &in.N, &in.M, &in.K, &in.S);
    in.P.resize(in.N);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.P[i]);
    scanf("%d %d %d %d", &in.A_p, &in.B_p, &in.C_p, &in.D_p);
    in.Q.resize(in.M);
    for (int i = 0; i < in.K; ++i) scanf("%d", &in.Q[i]);
    scanf("%d %d %d %d", &in.A_q, &in.B_q, &in.C_q, &in.D_q);
  }
  tbb::parallel_for_each(&case_data[0], &case_data[0] + T, process_case);
  for (int cs = 0; cs < T; ++cs) {
    printf("Case #%d: %lld\n", cs + 1, case_data[cs].seconds);
  }
  return 0;
}
