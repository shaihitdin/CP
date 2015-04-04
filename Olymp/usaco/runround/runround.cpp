/*
ID: shaihit1
PROG: runround
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;


const int oo = 2e9 + 7;

int n;
bool u[256];

inline bool check (vector <char> &t) {
	for (auto i = '0'; i <= '9'; ++i)
		u[i] = 0;
	u['0'] = 1;
	for (auto it : t) {
		if (u[it])
			return 0;
		u[it] = 1;
	}
	return 1;
}

inline vector <char> to_str (int x, const int &base) {
	vector <char> res;
	res.resize(0);
	while (x) {
		res.push_back (x % base);
		x /= base;
	}
	reverse (res.begin (), res.end());
	for (auto & it : res)
		it += '0';		
	return res;
}

inline bool jump (vector <char> &t) {
	for (auto i = '0'; i <= '9'; ++i)
		u[i] = 0;
	for (int i = 0; !(i == 0 && u[t[i]]); i = (i + (t[i] - '0')) % t.size()) {
		if (u[t[i]])
			return 0;
		u[t[i]] = 1;
	}
	for (int i = 0; i < t.size(); ++i)
		if (!u[t[i]])
			return 0;
	return 1;
}

int main() {
	
	freopen ("runround.in", "r", stdin);
	freopen ("runround.out", "w", stdout);
	
	cin >> n;

	for (int i = n + 1; i <= oo; ++i) {
		auto word = to_str (i, 10);
		if (check (word) && jump (word)) {
			cout << i << "\n";
			return 0;
		}
	}
}
