#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int go[N][20];
int len[N][2];
int lvl[N];

vector <pair <int, int> > g[N];

inline void dfs (const int &v, const int &p, const int &len1, const int &len2) {
	len[v][1] = len1;
	len[v][0] = len2;
	go[v][0] = p;
	lvl[v] = lvl[p] + 1;
	for (int i = 1; i <= 19; ++i)
		go[v][i] = go[go[v][i - 1]][i - 1];
	for (auto edge : g[v]) {
		bool flag = edge.first;
		int to = edge.second;
		if (to == p)
			continue;
		if (flag == 1)
			dfs (to, v, len1 + 1, 0);
		else
			dfs (to, v, 0, len2 + 1);
	}
}

inline int lca (int a, int b) {
	if (lvl[a] < lvl[b])
		swap (a, b);
	for (int i = 19; i >= 0; --i)
		if (lvl[go[a][i]] >= lvl[b])
			a = go[a][i];
	if (a == b)
		return a;
	for (int i = 19; i >= 0; --i) {
		if (go[a][i] != go[b][i]) {
			a = go[a][i];
			b = go[b][i];
		}
	}
	a = go[a][0];
	return a;
}


int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	cin >> n;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (make_pair (1, y));
		g[y].push_back (make_pair (0, x));
	}

	dfs (1, 0, 0, 0);
	
	int m;

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		int z = lca (x, y);
		if (lvl[x] - len[x][0] <= lvl[z] && lvl[y] - len[y][1] <= lvl[z])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}