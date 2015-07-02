#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7;

int c[N], sz[N];
bool flag[N];

multiset <int> g[N];

int pk[N];

inline void dfs (const int &v, const int &color) {
	c[v] = color;
	while (g[v].size ()) {
		int to = *g[v].begin ();
		g[v].erase (g[v].begin ());
		g[to].erase (g[to].find (v));
		if (!c[to])
			dfs (to, color);
		else
			flag[color] = 1;
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int n, k;
		
	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		g[i].insert (x);
		g[x].insert (i);
	}
	
	int cnt = 0;
	
	pk[0] = 1;

	for (int i = 1; i <= n; ++i)
		pk[i] = (pk[i - 1] * 1ll * (k - 1)) % bpr;

	for (int i = 1; i <= n; ++i)
		if (!c[i])
			dfs (i, ++cnt);

	for (int i = 1; i <= n; ++i)
		++sz[c[i]];
	
	int ans = 1;
	
	for (int i = 1; i <= cnt; ++i)
		if (flag[i] && sz[i] > 2) {
			if (sz[i] & 1)
				ans = (ans * 1ll * k) % bpr, ans = (ans * 1ll * pk[sz[i] - 2]) % bpr, ans = (ans * 1ll * (k - 2)) % bpr;
			else
				ans = (ans * 1ll * k) % bpr, ans = (ans * 1ll * pk[sz[i] - 1]) % bpr;
		}
		else
			ans = (ans * 1ll * k) % bpr, ans = (ans * 1ll * pk[sz[i] - 1]) % bpr;
	
	printf ("%d", ans);

	return 0;
}