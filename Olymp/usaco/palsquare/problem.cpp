/*
ID: shaihit1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

inline bool check_palindrome (const vector <int> &s) {
	for (int i = 0, j = (int)s.size() - 1; i < s.size() / 2; ++i, --j)
		if (s[i] != s[j])
			return 0;
	return 1;
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

inline void out (const vector <int> &z) {
	for (int i = 0; i < z.size(); ++i)
		cout << char (ans[z[i]]);
}
int main() {
	freopen ("palsquare.in", "r", stdin);
	freopen ("palsquare.out", "w", stdout);
	cin >> b;
	for (int i = 0; i < 10; ++i)
		ans[i] = (char)'0' + i;
	for (int i = 10; i <= 20; ++i)
		ans[i] = (char)i - 10 + 'A';
	for (int i = 1; i <= 300; ++i) {
		if (check_palindrome (to_str (i * i, b))) {
//			cout << i << " ";
			out (to_str (i, b));
			cout << " ";
			out (to_str (i * i, b));
			cout << "\n";
		}
	}
	return 0;
}
