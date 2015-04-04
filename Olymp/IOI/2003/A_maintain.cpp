#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 201;
int p[N], e[N], sz[N], n, m, a, b, c, ans;
bool u[N];
vector <pair <int, int> > g[N], cycle;
inline int get_comp (const int &x) {
	return ( (p[x] == x) ? (x) : p[x] = get_comp (p[x]));
}
inline void Union (int x, int y, const int &edge) {
	g[x].push_back (mkp (y, edge));
	g[y].push_back (mkp (x, edge));
	x = get_comp (x);
	y = get_comp (y);

	if (x == y)
		return;
		
	if (sz[x] > sz[y]) {
		p[y] = x;
		sz[x] += sz[y];
	}
	else {
		p[x] = y;
		sz[y] += sz[x];
	}
}

inline bool dfs (const int &v, const int &p) {
	if (u[v])
		return 1;
	u[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) { 
		auto to = g[v][i];
		if (to.F != p && dfs (to.F, v)) {
			cycle.push_back (mkp (v, i));
			return 1;
		}
	}
   return 0;
}
int main () {
	/*
	freopen ("maintain.in", "r", stdin);
	freopen ("maintain.out", "w", stdout);
	*/
	srand (time (0));
	//cin.sync();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = i, sz[i] = 1, e[i] = -1;
	for (int i = 1; i <= m; ++i) {
		//cin.sync();
		cin >> a >> b >> c;
		if (get_comp (a) == get_comp (b)) {
			int temp = -1, pos, v1, v2;
			memset (u, 0, sizeof (u));
			cycle.resize (0);
			u[a] = 1;
			dfs (b, 0);
			for (auto it : cycle) {
				if (g[it.F][it.S].S > temp) {
					temp = g[it.F][it.S].S;
					v1 = it.F;
					v2 = g[it.F][it.S].F;				
				}
			}
			if (temp > c) {
				ans -= temp;
				ans += c;
				for (int i = 0; i < g[v1].size(); ++i) {
					if (g[v1][i].F == v2) {
						g[v1].erase (g[v1].begin() + i);
						break;
					}				
				}
				for (int i = 0; i < g[v2].size(); ++i) {
					if (g[v2][i].F == v1) {
						g[v2].erase (g[v2].begin() + i);
						break;
					}				
				}
				g[a].push_back (mkp (b, c));
				g[b].push_back (mkp (a, c));
			}
		}
		else {
			Union (a, b, c);
			ans += c;
		}
		int j = 1;
		for (; j <= n && get_comp (j) == get_comp (1); ++j);
		if (j == n + 1)
			cout << ans;
		else
			cout << -1;
		cout << "\n";
		//cout.flush ();
	}
	return 0;
}