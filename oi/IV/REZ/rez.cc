#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10'001;

pair<int, int> rez[MAX_N];
// mem[i] -- maximum time if we only consider reservations 1 .. i.
int mem[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> rez[i].second >> rez[i].first;
  rez[n++] = make_pair(0, 0);
  sort(rez, rez + n);
  mem[0] = 0;
  for (int i = 1; i < n; ++i) {
    // binary search the last non-intersecting reservation.
    int lo = 0, hi = i - 1, mid;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if (rez[mid].first <= rez[i].second) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    mem[i] = max(mem[i - 1], rez[i].first - rez[i].second + mem[lo]);
  }
  cout << mem[n - 1] << endl;
  return 0;
}