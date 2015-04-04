#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 1000001;
int z[N], n, i, l, r, ans = 1;
string s;
int main() {
	freopen ("cyclic.in", "r", stdin);
	freopen ("cyclic.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> s;
	n = s.size();
	s += s;
	for (i = 1, l = 0, r = 0; i < n; ++i) {
		if (i < r)	z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < (int)s.size() && s[i + z[i]] == s[z[i]]) ++z[i];
		if (i + z[i] - 1 > r)	l = i, r = i + z[i] - 1;
	}
	for (i = 1; i < n; ++i) {
		if (s[i] < s[0])	++ans;
		if (z[i] != 0) {
			if (i + z[i] == (int)s.size())	continue;
			if (s[i + z[i]] < s[z[i]])	++ans;
		}
	}
	cout << ans;
return 0;
}