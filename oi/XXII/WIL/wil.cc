#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2'000'000;
using LL = unsigned long long;

LL w[MAX_N], ps[MAX_N + 1];

class Decha {
 public:
  Decha(int d) : d_(d){};
  void add(int idx) {
    LL val;
    if (idx < d_) {
      val = ps[idx + 1];
    } else {
      val = ps[idx + 1] - ps[idx + 1 - d_];
    }
    while (!v.empty() && v.back().second <= val) v.pop_back();
    v.emplace_back(std::max(0, idx + 1 - d_), val);
  }
  void pop(int idx) {
    if (v.front().first == idx) v.pop_front();
  }
  LL max() { return v.front().second; }

 private:
  int d_;
  deque<pair<int, LL>> v;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, d, res = -1, l = 0;
  LL s = 0, p;
  cin >> n >> p >> d;
  Decha decha(d);
  for (int i = 0; i < n; ++i) cin >> w[i];
  for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + w[i];
  for (int r = 0; r < n; ++r) {
    decha.add(r);
    s += w[r];
    while (s - decha.max() > p) {
      decha.pop(l);
      s -= w[l++];
    }
    res = max(res, r - l + 1);
  }
  cout << res << endl;
  return 0;
}
