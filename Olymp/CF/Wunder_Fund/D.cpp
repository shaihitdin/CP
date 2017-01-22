/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 100;
const ll oo = 1e15;

vector <int> g[N];
int p2[N], p[N];
ll x, y;
int sz[N], t_sz[N];

inline bool dfs (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!p[to] || dfs (p[to])) {
			p2[v] = to;
			p[to] = v;
			return 1;
		}
	}
	return 0;
}

inline void dfs2 (int v, int p) {
	sz[v] = 1
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	
	cin >> n >> x >> y;
	
	for (int i = 1; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		g[from].emplace_back (to);
		g[to].emplace_back (from);
	}
	
	if (x < y) {
		for (int run = 1; run;) {
			run = 0;
			memset (u, 0, sizeof (u));
			for (int i = 1; i <= n; ++i) {
				if (!p2[i]) {
					if (dfs (i))
						run = 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			cnt += (!p2[i]);
		}
		cout << cnt * 1ll * x + y * 1ll * (n - cnt);
	} else {
		dfs2 (1);
	}
	return 0;
}