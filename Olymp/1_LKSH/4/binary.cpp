#include <bits/stdc++.h>

using namespace std;

const int N = 4e5, sz = 1 << 19, inf = 1e9;

int a[N], pos[N];
string s;
int c[N], p[N], pn[N];

int main () {

	freopen ("binary.in", "r", stdin);
	freopen ("binary.out", "w", stdout);

	for (int i = 1; i < N; ++i)
		upd (i, inf);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		pos[a[i]] = i;
	for (int i = 1; i <= n; ++i)
		if (a[i] != n - i + 1)
			goto check;
	for (int i = 1; i <= n; ++i)
		printf ("0");
	return 0;
	check:;

	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		s.resize (0);
		s.resize (n);
		for (int i = 0; i < n; ++i)
			s[i] = pos[i] >= mid;
		
		for (int i = 0; i < n; ++i)
			++cnt[(int)s[i]];
		for (int i = 1; i < 2; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i)
			p[--cnt[(int)s[i]]] = i;
		c[0] = 0;
		for (int i = 1; i < n; ++i)
			if(s[p[i]] != s[p[i - 1]])
				c[p[i]] = c[p[i - 1]] + 1;
			else
				c[p[i]] = c[p[i - 1]];
		
		for (int k = 0; (1 << k) < n; ++k) {
			int k1 = 1 << k;
			for (int i = 0; i < n; ++i) {
				pn[i] = (p[i] - k1 + n);
				if (pn[i] >= n)
					pn[i] -= n;
			}
			memset (cnt, 0, sizeof (cnt[0] * n));
			for (i = 0; i < n; ++i)
				++cnt[c[pn[i]]];
			for (i = 1; i < n; ++i)
				cnt[i] += cnt[i - 1];
			for (i = n - 1; i >= 0; --i)
				p[--cnt[c[pn[i]]]] = pn[i];
			cn[p[0]] = 0;
			for (i = 1; i < n; ++i) {
				int x = p[i], y = p[i-1], k1 = 1 << k;
				if(c[x] != c[y] || 
				c[(x + k1) >= n ? x + k1 - n : x + k1] != c[(y + k1) >= n ? y + k1 - n : y + k1])
					cn[p[i]] = cn[p[i - 1]] + 1;
				else
					cn[p[i]] = cn[p[i - 1]];
			}
			memcpy (c, cn, sizeof (cn[0]) * n);
		}

	}
	
	return 0;
}