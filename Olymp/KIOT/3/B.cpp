#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

typedef long long ll;

struct edge {
	int x, y, z;
};

edge e[N];
int n;
vector <pair <ll, ll> > g[N];
ll d[N], up[N], cnt[N];
bool u[N];
ll total;

inline void dfs1 (const int &v, const int &p, const int &be) {
	d[v] = 0;
	for (auto ed : g[v]) {
		int to = ed.first;
		int dist = ed.second;
		if (to == p)
			continue;
		if (v == e[be].x && to == e[be].y)
			continue;
		else if (v == e[be].y && to == e[be].x)
			continue;		
		dfs1 (to, v, be);
		cnt[v] += cnt[to];
		d[v] += d[to] + cnt[to] * dist;
	}
	++cnt[v];
}

inline void dfs2 (const int &v, const int &p, const int &be) {
	for (auto ed : g[v]) {
		int to = ed.first;
		int dist = ed.second;
		if (to == p)
			continue;
		if (v == e[be].x && to == e[be].y)
			continue;
		else if (v == e[be].y && to == e[be].x)
			continue;
		up[to] = up[v] + d[v] - d[to] - cnt[to] * dist + (total - cnt[to]) * dist;
		dfs2 (to, v, be);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].emplace_back (make_pair (y, z));
		g[y].emplace_back (make_pair (x, z));
		e[i].x = x;
		e[i].y = y;
		e[i].z = z;
	}

	ll ans = 1e18;	
	
	for (int i = 1; i < n; ++i) {
		memset (d, 0, sizeof (d));
		memset (up, 0, sizeof (up));
		memset (u, 0, sizeof (u));
		memset (cnt, 0, sizeof (cnt));
		dfs1 (e[i].x, 0, i);
		total = cnt[e[i].x];
		dfs2 (e[i].x, 0, i);
		ll total1 = total;
		ll part1 = 1e18;
		for (int j = 1; j <= n; ++j) {
			if (!cnt[j])
				continue;
			u[j] = 1;
			part1 = min (part1, d[j] + up[j]);
		}
		dfs1 (e[i].y, 0, i);
		total = cnt[e[i].y];
		dfs2 (e[i].y, 0, i);
		ll total2 = total;
		ll part2 = 1e18;
		for (int j = 1; j <= n; ++j) {
			if (u[j])
				continue;
			part2 = min (part2, d[j] + up[j]);
		}
	    ll sum = 0;
	    for (int j = 1; j <= n; ++j)
			sum += up[j] + d[j];
		
		assert (sum % 2 == 0);

		sum /= 2;
		
		ans = min (ans, sum + (part1 + (e[i].z * 1ll * total1)) * total2 + part2 * total1);
	}
	
	cout << ans;
	
	return 0;
}