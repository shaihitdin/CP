/*
ID: shaihit1
PROG: zerosum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int n;

inline void rec (const int &num, const int &sum, const int &element, const int &sign, string && ans) {
	if (num == n + 1) {
		if (sum + element == 0)
			cout << ans << "\n";
		return;
	}
	rec (num + 1, sum, element * 10 + (sign * num), sign, ans + ' ' + char ('0' + num));
	rec (num + 1, sum + element, num, +1, ans + '+' + char ('0' + num));
	rec (num + 1, sum + element, -num, -1, ans + '-' + char ('0' + num));
}


int main() {
	
	freopen ("zerosum.in", "r", stdin);
	freopen ("zerosum.out", "w", stdout);

	cin >> n;

	rec (2, 0, 1, 1, "1");

	return 0;
}
