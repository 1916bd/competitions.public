// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int solve(int N, const string& s) {
	int lpos = -1;
	bool l_isx;
	int res = 0, L = 0;

	for(char c : s) {
		if(c == 'X') {
			if(lpos < 0) { // first
				//
			} else {
				if(!l_isx) {
					// O -> X
					++res;
				}
			}
			l_isx = true;
			lpos = L++;
		} else if(c == 'O') {
			if(lpos < 0) { // first
				//
			} else {
				if(l_isx) {
					// X -> O
					++res;
				}
			}
			l_isx = false;
			lpos = L++;
		} else if(c == 'F') {
			++L;
		} else if(c == '.') {
			/// ...
		}
	}
	return res;
}

int main() {
	   std::ios::sync_with_stdio(false);
	   int T, N;
	   string S;

	   cin >> T;
	   for(int cs = 1; cs <= T; ++cs) {
	   		cin >> N >> S;
	   		cout << "Case #" << cs << ": " << solve(N, S) << endl;
	   } 
	return 0;
}