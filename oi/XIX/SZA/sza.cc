#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 100'000;
const int MAX_P = 1'000'000;

int latest_avail[MAX_K + 1];
int res[MAX_P];
vector<tuple<int, int, int, int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // +przedmiot [2*x+0, x+d, c]
  // +zapytanie [2*x+1, x+d, c]
  int n, p, a, b, c, m, kk, s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c >> a >> b;
    v.emplace_back(2 * a + 0, b, c, -1);
  }
  cin >> p;
  for (int i = 0; i < p; ++i) {
    cin >> m >> kk >> s;
    v.emplace_back(2 * m + 1, m + s, kk, i);
  };
  sort(v.begin(), v.end());
  latest_avail[0] = INT_MAX;
  for (const auto& [_, xy, val, idx] : v) {
    if (idx < 0) {  // przedmiot
      for (int k = MAX_K; k >= val; --k)
        latest_avail[k] = max(latest_avail[k], min(latest_avail[k - val], xy));
    } else {  // zapytanie
      res[idx] = latest_avail[val] > xy;
    }
  }
  for (int i = 0; i < p; ++i) cout << (res[i] ? "TAK" : "NIE") << endl;
  return 0;
}