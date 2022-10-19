#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  stack<int> s;
  int n, d, w, res = 0;
  s.push(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d >> w;
    while (s.top() > w) s.pop();
    if (s.top() != w) {
      s.push(w);
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}