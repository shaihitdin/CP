#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 100, K = 501;
const ll inf = 1e15;
 
vector <int> add[N], del[N];
 
ll d[N][K];
int a[N];
short cost[N];
int cnt[210];
 
/*
inline void amax (ll &x, const ll &y) {
	if (x < y)
		x = y;
}
*/ 
 
int main () {
 
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
 
	int t;
 
	scanf ("%d", &t);
 
	while (t--) {
		int n, k, m;
		scanf ("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);
		for (int i = 1; i <= n; ++i)
			add[i].resize (0), del[i].resize (0);
		
		for (int i = 1; i <= m; ++i) {
			int l, r, c;
			scanf ("%d%d%d", &l, &r, &c);
			add[l].emplace_back (c);
			del[r].emplace_back (c);
		}
 
	    for (int i = 1; i <= n; ++i) {
	    	for (auto it : add[i])
	    		++cnt[it];
	    	int j = 0;
	    	for (; j <= 200 && !cnt[j]; ++j);
	    	if (j == 201) cost[i] = 1000;
	    	else cost[i] = j;
	    	for (auto it : del[i])
	    		--cnt[it];
	    }
 
		
		for (int i = 1; i <= n + 1; ++i)
			for (int j = 0; j <= k; ++j)
				d[i][j] = -inf;
		
		d[1][k] = 0;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				d[i + 1][j] = max (d[i + 1][j], d[i][j] + a[i]);
				if (cost[i] <= j)
					d[i + 1][j - cost[i]] = max (d[i + 1][j - cost[i]], d[i][j]);
			}
		}
 
		ll ans = -inf;
		for (int i = 0; i <= k; ++i)
			ans = max (ans, d[n + 1][i]);
		printf ("%lld\n", ans);
	}
 
	return 0;
} 