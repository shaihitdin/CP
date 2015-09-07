#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int state[N], cnt[N];
int permanent[N];
int p[N], pa[N];
int u[N], cnt_u;

vector <pair <int, int> > g[N];

inline bool dfs (const int &v) {
    if (u[v] == cnt_u || permanent[v])
    	return 0;
    u[v] = cnt_u;
	for (auto edge : g[v]) {
		int to = edge.first;
		if (!p[to] || dfs (p[to])) {
			state[v] = edge.second;
			pa[v] = to;
			p[to] = v;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			g[abs (x)].emplace_back (make_pair (i, x));
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (g[i].size () == 1 || (g[i].size () == 2 && g[i][0].second == g[i][1].second)) {
			permanent[i] = g[i][0].second;
			p[g[i][0].first] = i;
			p[g[i][1].first] = i;
			pa[i] = g[i][0].first;
			state[i] = permanent[i];
		}
	}

	for (int run = 1; run; ) {
		run = 0;
		for (int i = 1; i <= m; ++i) {
			if (!pa[i]) {
				++cnt_u;
				dfs (i);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";

	for (int i = 1; i <= m; ++i)
		cout << (state[i] > 0);
	
	return 0;
}