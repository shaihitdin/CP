#include <bits/stdc++.h>
#include <string>

using namespace std;

const int N = 1e6 + 1;

string s;
int c[N], cn[N], p[N], pn[N], cnt[N];

int main () {
	freopen ("cyclic.in", "r", stdin);
	freopen ("cyclic.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i)
		++cnt[(int)s[i]];
	for (int i = 0; i < 256; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[(int)s[i]]] = i;
	c[p[0]] = 1;
	int classes = 1;
	for (int i = 1; i < n; ++i) {
		if (s[p[i]] != s[p[i - 1]]) {
			++classes;
		}
		c[p[i]] = classes;
	}
	for (int h = 0; (1 << h) < n && classes < n; ++h) {
		for (int i = 0; i < n; ++i) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += n;
		}
		memset (cnt, 0, sizeof (cnt[0]) * (n + 1));
		for (int i = 0; i < n; ++i)
			++cnt[c[p[i]]];
		for (int i = 1; i < n; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 1;
		classes = 1;
		for (int i = 1; i < n; ++i) {
			int mid1 = (p[i] + (1 << h) );
			int mid2 = (p[i - 1] + (1 << h) );
			while (mid1 >= n)
				mid1 -= n;
			while (mid2 >= n)
				mid2 -= n;
			if (c[p[i]] == c[p[i - 1]] && c[mid1] == c[mid2])
				cn[p[i]] = classes;
			else
				cn[p[i]] = ++classes;
		}
		memcpy (c, cn, sizeof (cn[0]) * (n + 1));
	}
	int lost = 0;
	for (int i = 0; i < n; ++i) {
		if (c[p[i]] != c[p[i - 1]])
			lost = i;
		if (p[i] == 0)
			cout << lost + 1;
	}
	return 0;
}