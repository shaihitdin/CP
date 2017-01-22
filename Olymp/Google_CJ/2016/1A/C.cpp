/// Forever

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2050;

int f[N];
int cc;
int cnum[N], len[N], cnum2[N];
int u[N];
int p[N];
int d[N];
int val[N];
int cnt[N];

inline void cycle_found (int v, int u) {
	++cc;
	for (int x = v; x != p[u]; x = p[x]) {
		++len[cc];
		cnum[x] = cc;
	}
}

inline void dfs (int v, int pp = -1) {
	if (u[v] == 1)
		return;
	if (u[v] == 2) {
		cycle_found (pp, v);
		return;
	}
	u[v] = 2;
	p[v] = pp;
	dfs (f[v], v);
	u[v] = 1;
}

inline void dfs2 (int v) {
	if (u[v])
		return;
	u[v] = 1;
	if (cnum[v]) {
		cnum2[v] = v;
		return;
	}
	dfs2 (f[v]);
	cnum2[v] = cnum2[f[v]];
	cnum[v] = cnum[f[v]];
}

inline void dfs3 (int v) {
	if (u[v])
		return;
	u[v] = 1;
	if (cnum2[v] == v) {
		d[v] = 0;
		return;
	}
	dfs3 (f[v]);
	++cnt[cnum[v]];
	d[v] = d[f[v]] + 1;
	val[cnum2[v]] = max (val[cnum2[v]], d[v]);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> f[i];
		int ans = 0;
		memset (u, 0, sizeof (u));
		memset (len, 0, sizeof (len));
		memset (val, 0, sizeof (val));
		memset (d, 0, sizeof (d));
		memset (cnum, 0, sizeof (cnum));
		memset (cnum2, 0, sizeof (cnum2));
		memset (cnt, 0, sizeof (cnt));
		cc = 0;
		for (int i = 1; i <= n; ++i)
			dfs (i);
		for (int i = 1; i <= cc; ++i)
			ans = max (ans, len[i]);
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= n; ++i)
			dfs2 (i);
		memset (u, 0, sizeof (u));
		memset (val, 0, sizeof (val));
		for (int i = 1; i <= n; ++i)
			dfs3 (i);
		for (int i = 1; i <= n; ++i)
			if (f[f[i]] == i)
				ans = max (ans, 2 + val[i] + val[f[i]]);
		//cerr << "\n";
		cout << ans << "\n";
	}
	
	
	return 0;
}