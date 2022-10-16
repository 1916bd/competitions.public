#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300'000;
vector<int> g[MAX_N + 1];
int extra[MAX_N + 1];  // extra arcs needed in the subtree rooted at v
int M;

void dfs(int x, int p) {
  extra[x] = 0;
  for (auto v : g[x])
    if (v != p) {
      dfs(v, x);
      extra[x] += extra[v] + 1;
    }
  extra[x] = max(extra[x] - M, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    M = lo + (hi - lo) / 2;
    dfs(1, -1);
    if (extra[1] == 0) {
      hi = M;
    } else {
      lo = M + 1;
    }
  }
  cout << lo << endl;
  return 0;
}