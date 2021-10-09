// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int solve() {
	int R, C, K;
	vector<int> cost_up, cost_down;
	vector<string> G;
	cin >> R >> C >> K; K--;
	cost_up.assign(R-K+1, 0);
	cost_down.assign(K+2, 0);
	G.resize(R);
	for(int r = 0; r < R; ++r) cin >> G[r];
	// up
	for(int c = 0; c < C; ++c) {
		int st = 0;
		for(int r = 0; r <= R; ++r) {
			if(r < R && G[r][c] == 'X') ++st;
			if(r >= K) {
				// shift by r - K
				if (st >= K+1 || (r < R && G[r][c] == 'X')) {
					++cost_up[r - K];
				}
			}
		}
	}
	// down
	for(int c = 0; c < C; ++c) {
		int st = 0;
		for(int r = R-1; r >= -1; --r) {
			if(r >= 0 && G[r][c] == 'X') ++st;
			if(r <= K) {
				// shift by r - K
				if (st >= R-K || (r >= 0 && G[r][c] == 'X')) {
					++cost_down[K - r];
				}
			}
		}
	}
	int best = C;
	for(int r = 0; r < R-K+1; ++r) {
		best = min(best, cost_up[r] + r);
	}
	for(int r = 0; r < K+2; ++r) {
		// cout << "cost_down " << r << " " << cost_down[r] + r << endl; 
		best = min(best, cost_down[r] + r);
	}
	return best;
}

int main() {
	   std::ios::sync_with_stdio(false);
	   int T;

	   cin >> T;
	   for(int cs = 1; cs <= T; ++cs) {
	   		cout << "Case #" << cs << ": " << solve() << endl;
	   } 
	return 0;
}