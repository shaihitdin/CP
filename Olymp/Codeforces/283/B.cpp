#include <iostream>
#include <stdio.h>
using namespace std;
string s, t, ans;
int n, diff, j;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		ans += '9';
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		t = '0';
		diff = 10 - (s[i] - '0');
		j = i + 1;
		while (j != i) {
			if (j == s.size())
				j = 0;
			if (j == i)
				break;
			t += char ('0' + ((s[j] - '0' + diff) % 10));
			++j;
		}
		if (t < ans)
			ans = t;
	}
	cout << ans;
	return 0;
}