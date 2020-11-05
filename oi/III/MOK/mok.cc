#include <bitset>
#include <iostream>
#include <queue>
using namespace std;

int n;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int encode(int* a) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res <<= 6;
    res += a[i];
  }
  return res;
}

void decode(int t, int* a) {
  for (int i = n - 1; i >= 0; --i) {
    a[i] = t & 63;
    t >>= 6;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int g = 0, cap[4], out[4], aux[4], infeasible = 0, end;
  bitset<1 << 24> mem;
  queue<pair<int, int>> q;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cap[i];
    g = gcd(g, cap[i]);
  }
  for (int i = 0; i < n; ++i) {
    cin >> out[i];
    infeasible += out[i] % g;
  }
  if (infeasible) {
    cout << "NIE" << endl;
    return 0;
  }
  end = encode(out);

  auto ins = [&](int v, int cost) {
    if (mem[v]) return;
    mem[v] = 1;
    q.emplace(v, cost);
  };

  ins(encode(cap), 0);
  while (!q.empty()) {
    auto el = q.front();
    q.pop();
    if (el.first == end) {
      cout << el.second << endl;
      return 0;
    }
    decode(el.first, aux);
    // fill j from i
    for (int i = 0; i < n; ++i) {
      if (aux[i] == 0) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j || aux[j] == cap[j]) continue;
        int diff = min(aux[i], cap[j] - aux[j]);
        aux[i] -= diff;
        aux[j] += diff;
        ins(encode(aux), el.second + 1);
        aux[i] += diff;
        aux[j] -= diff;
      }
    }
    // dump i
    for (int i = 0; i < n; ++i) {
      if (!aux[i]) continue;
      int t = aux[i];
      aux[i] = 0;
      ins(encode(aux), el.second + 1);
      aux[i] = t;
    }
  }
  return 0;
}
