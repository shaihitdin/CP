#include <bits/stdc++.h>

using namespace std;

const int lg = 17, N = 1e5 + 100, bpr = 1e9 + 7, M = 3e6 + 100;

int lvl[N][lg + 1];
int ans;
int add_type[N][2];
int up[N][2];
int h[N];
vector <pair <int, int> > g[N];
int pw[M];

inline int gp (const int &v, const int &rr) {
	int now = v;
	for (int i = lg; i >= 0; --i)
		if ((rr >> i) & 1)
			now = lvl[now][i];
	return now;
}

inline int lca (int x, int y) {
	if (h[x] > h[y])
		swap (x, y);
	y = gp (y, h[y] - h[x]);
	if (x == y)
		return x;
	for (int i = lg; i >= 0; --i)
		if (lvl[x][i] != lvl[y][i])
			x = lvl[x][i], y = lvl[y][i];
	x = lvl[x][0];
	return x;
}

inline void dfs (const int &v, const int &p) {

	lvl[v][0] = p;
	h[v] = h[p] + 1;
		
	for (int i = 1; i < lg; ++i)
		lvl[v][i] = lvl[lvl[v][i - 1]][i - 1];
	
	for (auto to : g[v]) {
		if (to.first == p)
			continue;
		dfs (to.first, v);
	}

}



inline void dfs2 (const int &v, const int &p) {	
	
	for (auto to : g[v]) {
		if (to.first == p)
			continue;
		dfs2 (to.first, v);
		if (to.second == 1) {
			if (up[to.first][0] > 0)
				ans = (ans + pw[up[to.first][0] - 1]) % bpr;
		} else if (to.second == 2) {
		    if (up[to.first][1] > 0)
				ans = (ans + pw[up[to.first][1] - 1]) % bpr;
		}
		up[v][0] += up[to.first][0];
		up[v][1] += up[to.first][1];
	}
	up[v][0] += add_type[v][0];
	up[v][1] += add_type[v][1];

}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	
	int n, m;
	
	pw[0] = 1;

	for (int i = 1; i < M; ++i)
		pw[i] = (pw[i - 1] * 2) % bpr;
	
	for (int i = 1; i < M; ++i)
		pw[i] = (pw[i - 1] + pw[i]) % bpr;
	
	cin >> n;	
	
	
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 0) {
			g[x].emplace_back (make_pair (y, 0));
			g[y].emplace_back (make_pair (x, 0));
		} else {
			g[x].emplace_back (make_pair (y, 1));
			g[y].emplace_back (make_pair (x, 2));
		}
	}

	
	dfs (1, 0);
	
	cin >> m;

	int pr = 1;

	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		++add_type[pr][0];
		int y = lca (x, pr);
		--add_type[y][0];
		++add_type[x][1];
		--add_type[y][1];
		
		pr = x;
	}
	
	dfs2 (1, 0);
	
	
	cout << ans;
	
	return 0;
}