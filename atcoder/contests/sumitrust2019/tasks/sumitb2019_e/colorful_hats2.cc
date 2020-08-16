#include <iostream>
#include <vector>

const int MAX_N = 1000000;
const int MOD = 1000000007;

int c[MAX_N];
inline void mul_mod(int& x, int y) { x = (long long)x * y % MOD; }

int main() {
  int n, a, res = 1;
  std::cin >> n;
  c[0] = 3;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    mul_mod(res, c[a] - c[a + 1]);
    c[a + 1]++;
  }
  std::cout << res << std::endl;

  return 0;
}
