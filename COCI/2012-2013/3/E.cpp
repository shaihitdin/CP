#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

const int N = 3001, bp = 1e9 + 7;

string s[N];
int n;
int c[N], csz[N], f[N], clen[N], sz;
int lcp[N];
int main () {
	freopen ("herkabe.in", "r", stdin);
	freopen ("herkabe.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bp;

	sort (s + 1, s + n + 1);
	for (int i = 2; i <= n; ++i) {
		int len = min (s[i].size(), s[i - 1].size()); 
		int j = 0;
		for (; j < len && s[i][j] == s[i - 1][j]; ++j);
		lcp[i] = j;
	}
	lcp[1] = lcp[2];
	for (int i = 1; i <= n; ++i) {
		int now = lcp[i];
		int j = i - 1;
		for (; lcp[j] != 0 && now < lcp[j]; --j);
		//cerr << i << " " << j << "\n";
		if (now != clen[c[j]]) {
			c[i] = ++sz;
			csz[sz] = 1;
			clen[sz] = lcp[i];
			if (j != 0 && lcp[j] < now) {
				--csz[c[j]];
				c[j] = c[i];
				++csz[c[j]];
			}
		}
		else {
			c[i] = c[j];
			++csz[c[i]];
		}
	}
	int res = 1;
	for (int i = 1; i <= sz; ++i) {
		res = (res * 1ll * csz[i]) % (1ll * bp);
	}
	res = (res * 1ll * f[sz]) % bp;
	cout << res;
	return 0;
}