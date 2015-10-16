#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 100;
const ll oo = 1e16;


set <pair <ll, ll> > Set;

ll d[N], d1[N];
ll tin[N], fup[N], timer;
vector <ll> g[N], grev[N];
ll to[N], from[N], cost[N];
bool bridge[N];
ll p[N];
ll n, m, s, t;
bool u[N];
ll colors[N];
ll clrsz = 1;

inline void dfs (const ll &v, const ll &p) {
	tin[v] = ++timer;
	fup[v] = timer;
	for (auto it : g[v]) {
		if (p == it)
			continue;
		ll tt = to[it];
		if ((d[v] + d1[tt] + cost[it] != d[t]))
			continue;
		if (tin[tt]) {
			fup[v] = min (fup[v], tin[tt]);
		} else {
			dfs (tt, it);
			fup[v] = min (fup[v], fup[tt]);
			if (fup[tt] > tin[v])
				bridge[it] = 1;
		}
	}
	for (auto it : grev[v]) {
		if (p == it)
			continue;
		ll tt = from[it];
		if ((d1[v] + d[tt] + cost[it] != d[t]))
			continue;
		if (tin[tt]) {
			fup[v] = min (fup[v], tin[tt]);
		} else {
			dfs (tt, it);
			fup[v] = min (fup[v], fup[tt]);
			if (fup[tt] > tin[v])
				bridge[it] = 1;
		}
	}

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> s >> t;

	for (ll i = 1; i <= m; ++i) {
		cin >> from[i] >> to[i] >> cost[i];
		g[from[i]].push_back (i);
		grev[to[i]].push_back (i);
	}
	
	
	for (ll i = 1; i <= n; ++i)
		d[i] = oo;
	
	d[s] = 0;

	Set.insert (make_pair (d[s], s));
	
	while (Set.size ()) {
		ll v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (ll it : g[v]) {
			ll tt = to[it], add = cost[it];
			if (d[tt] > d[v] + add) {
				Set.erase (make_pair (d[tt], tt));
				d[tt] = d[v] + add;
				Set.insert (make_pair (d[tt], tt));
			}
		}
	}
	
	for (ll i = 1; i <= n; ++i)
		d1[i] = oo;	
	
	d1[t] = 0;

	Set.insert (make_pair (d1[t], t));
	
	while (Set.size ()) {
		ll v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (ll it : grev[v]) {
			ll tt = from[it], add = cost[it];
			if (d1[tt] > d1[v] + add) {
				Set.erase (make_pair (d1[tt], tt));
				d1[tt] = d1[v] + add;
				Set.insert (make_pair (d1[tt], tt));
			}
		}
	}
	
	
	dfs (s, -1);

	for (ll i = 1; i <= m; ++i) {
		if (bridge[i]) {
			cout << "YES\n";
			continue;
		}
		ll tt = from[i];
		if (d[tt] + 1 + d1[to[i]] < d[t]) {
			//cerr << d[tt] << " " << d1[to[i]] << "\n";
			cout << "CAN " << cost[i] - (d[t] - 1 - (d[tt] + d1[to[i]])) << "\n";
			continue;
		}
		cout << "NO\n";
	}
	
	return 0;
}