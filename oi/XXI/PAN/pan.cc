#include <bits/stdc++.h>
using namespace std;

int solve(int a1, int a2, int b1, int b2) {
  int res = 1, t;
  for (int i = 1; i * i <= a2; ++i) {
    t = i;
    if (a2 / t * t >= a1 && (b2 / t * t) >= b1) res = max(res, t);
    t = a2 / i;
    if (a2 / t * t >= a1 && (b2 / t * t) >= b1) res = max(res, t);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, s1, s2, w1, w2;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s1 >> s2 >> w1 >> w2;
    cout << max(solve(s1, s2, w1, w2), solve(w1, w2, s1, s2)) << endl;
  }
  return 0;
}