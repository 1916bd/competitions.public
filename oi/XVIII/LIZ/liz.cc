#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1'000'000;
pair<int, int> mem[2 * MAX_N];
string s;

void generate(int l, int r, int total) {
  while (total > 0) {
    mem[total] = {l + 1, r + 1};
    if (s[l] == 'T') {
      ++l;
    } else if (s[r] == 'T') {
      --r;
    } else {
      ++l;
      --r;
    };
    total -= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, l, k;
  cin >> n >> q;
  cin >> s;
  l = s.size();
  // W - 1, T - 2
  int total = accumulate(s.begin(), s.end(), 0, [](int acc, char c) {
    return acc + (c == 'W' ? 1 : 2);
  });
  generate(0, l - 1, total);
  auto first_w = s.find_first_of('W');
  auto last_w = s.find_last_of('W');
  if (first_w != string::npos) {
    if (first_w < l - 1 - last_w) {
      generate(first_w + 1, l - 1, total - 2 * first_w - 1);
    } else {
      generate(0, last_w - 1, total - 2 * (l - 1 - last_w) - 1);
    }
  }
  while (q--) {
    cin >> k;
    if (mem[k].first == 0) {
      cout << "NIE" << endl;
    } else {
      cout << mem[k].first << " " << mem[k].second << endl;
    }
  }
  return 0;
}
