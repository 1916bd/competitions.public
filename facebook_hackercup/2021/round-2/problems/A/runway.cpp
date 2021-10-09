// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int solve() {
	int N, M, x;
	vector<pair<int,int>> a, new_a; // style, #changes
	vector<int> tmp, junk_a, junk_b;
	cin >> N >> M;
	for(int i = 0; i < M; ++i) {
		cin >> x;
		a.emplace_back(x, 0);
	}
	tmp.resize(M);
	for(int round = 0; round < N; ++round) {
		sort(a.begin(), a.end());
		for(int i = 0; i < M; ++i) cin >> tmp[i];
		sort(tmp.begin(), tmp.end());
		junk_a.clear();
		junk_b.clear();
		new_a.clear();
		new_a.reserve(M);
		int ptr = 0;
		//cout << "M = " << M << endl;
		int aptr;
		for(aptr = 0; aptr < M && ptr < M;) {
			if(a[aptr].first == tmp[ptr]) {
				new_a.push_back(a[aptr]);
				ptr++; aptr++;
			} else if(a[aptr].first < tmp[ptr]) {
				junk_a.push_back(a[aptr].second);
				aptr++;
			} else {
				junk_b.push_back(tmp[ptr]);
				ptr++;
			}
		}
		while(aptr < M) {
			junk_a.push_back(a[aptr++].second);
		}
		while(ptr < M) {
			junk_b.push_back(tmp[ptr++]);
		}
		// cout << junk_a.size() << " " << junk_b.size() << endl;
		for(int i = 0; i < junk_a.size(); ++i) {
			new_a.emplace_back(junk_b[i], junk_a[i] - 1);
		}
		a = new_a;
	}
	int res = 0;
	for(int i = 0; i < M; ++i) res += max(-a[i].second - 1, 0);
	return res;
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