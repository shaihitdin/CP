#include <bits/stdc++.h>

using namespace std;

const int N = 2500;

int fup[N], tin[N], timer;

bool bridge[N][N];

inline void dfs (const int &v, int p) {
	tin[v] = ++timer;
	fup[v] = timer;
	u[v] = 1;
	for (auto to : g[v]) {
		if (to == p) {
			p = -1;
			continue;
		}
		if (u[to]) {
			fup[v] = min (fup[v], tin[to]);
		} else {
			dfs (to, v);
			if (tin[v] < fup[to])
				bridge[v][to] = bridge[to][v] = 1;
			fup[v] = min (fup[v], fup[to]);
		}
	}
}

int col_cnt = 1;
int col[N];

inline void dfs2 (const int &v, const int &col) {
	u[v] = 1;
	for (auto to : g[v]) {
		if (u[to])
			continue;
		if (bridge[v][to] == 1)
			dfs2 (v, ++col_cnt);
		else
			dfs2 (v, col);
	}
}

char win[N];
bool other_way[N];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			g[i].resize (0);
		
		memset (tin, 0, sizeof (tin));
		memset (fup, 0, sizeof (fup));
		memset (u, 0, sizeof (u));
		memset (bridge, 0, sizeof (bridge));

		while (m--) {
			cin >> x >> y;
			g[x].push_back (y);
			g[y].push_back (x);
		}
		dfs (1);
		memset (u, 0, sizeof (u));
		col_cnt = 0;
		dfs2 (1, ++col_cnt);

		for (int i = 1; i <= n; ++i) {
			memset (win, 2, sizeof (win));
			memset (other_way, 0, sizeof (other_way));
			for (int j = 1; j <= n; ++j)
				for (auto to : 
		}

	}

	return 0;
}