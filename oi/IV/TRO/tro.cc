#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int out[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x, y, res = 0;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    ++out[x];
    ++out[y];
  }
  for (int i = 1; i <= n; ++i) {
    res += out[i] * (n - 1 - out[i]);
  }
  cout << n * (n - 1) * (n - 2) / 6 - res / 2 << endl;
  return 0;
}
