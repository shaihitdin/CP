/*
ID: shaihit1
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

inline bool check_palindrome (const vector <int> &s) {
	vector <int> t = s;
	reverse (t.begin(), t.end());
	return t == s;
}

int b;

char ans[256];
inline vector <int> to_str (int x, const int &base) {
	vector <int> res;
	res.resize(0);
	while (x) {
		res.push_back (x % base);
		x /= base;
	}
	reverse (res.begin (), res.end());
	return res;
}

int n, s;

int main() {
	freopen ("dualpal.in", "r", stdin);
	freopen ("dualpal.out", "w", stdout);
	auto asa = 0;	
	cin >> n >> s;
	
	for (int i = s + 1; n; ++i) {
		int cnt = 0;
		for (int j = 2; j <= 10; ++j) {
			if (check_palindrome (to_str (i, j))) {
				++cnt;
				if (cnt == 2) {
					cout << i << "\n";
					--n;
					break;
				}
			}
		}
	}
	return 0;
}
