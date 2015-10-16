#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, K = 510;

typedef long long ll;

int n, m, k, b;
vector <int> g[N], g_del[N];
ll a[N];
ll d[N][K];
int till[N];
int cost[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> k >> b;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		g[l].emplace_back (r);
	}
	
	multiset <int> Set;
	
	for (int i = 1; i <= n; ++i) {
		for (auto it : g[i])
			Set.insert (it);
		while (Set.size () && *Set.begin () == i)
			Set.erase (Set.begin ());
		if (Set.size ())
			till[i] = *Set.rbegin ();
		else
			till[i] = i;
	}
	
	for (int i = 1; i <= n; ++i)
		g[i].clear ();
			
	for (int i = 1; i <= k; ++i) {
		int l, r, c;
		cin >> l >> r >> c;
		g[l].emplace_back (c);
		g_del[r].emplace_back (c);
	}
	
	Set.clear ();
	
	const int oo = 1e9;
	
	for (int i = 1; i <= n; ++i) {
		for (auto it : g[i])
			Set.insert (it);
	
	    if (Set.size ())
	    	cost[i] = *Set.begin ();
		else
			cost[i] = oo;
	    
	    for (auto it : g_del[i])
	    	Set.erase (Set.find (it));
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= b; ++j)
			d[i][j] = -oo;
	
	d[1][b] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = b; j >= 0; --j) {
			if (cost[i] <= j)
				d[till[i] + 1][j - cost[i]] = max (d[till[i] + 1][j - cost[i]], d[i][j] + a[i]);
			d[i + 1][j] = max (d[i + 1][j], d[i][j]);
		}
	}

	ll ans = 0;
	
	for (int j = 0; j <= b; ++j)
		ans = max (ans, d[n + 1][j]);

	cout << ans;
	
	return 0;
}