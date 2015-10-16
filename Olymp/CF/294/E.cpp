#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1, dd = 17;

int p[N][dd], h[N];
bool u[N];
int sz[N];
vector <int> g[N];
int n, m;

inline void dfs (const int &v, const int &a) {
	u[v] = 1;
	h[v] = h[a] + 1;
	if (a != v) {
		p[v][0] = a;
		for (int i = 1; i < dd; ++i)
			p[v][i] = p[p[v][i - 1]][i - 1];
	} else {
		for (int i = 0; i < dd; ++i)
			p[v][i] = v;
	}
	sz[v] = 1;
	for (int to : g[v]) {
		if (!u[to]) {
			dfs (to, v);
			sz[v] += sz[to];
		}
	}
}

inline int gp (const int &v, const int &rr) {
	int now = v;
	for (int i = dd - 1; i >= 0; --i)
		if ((rr >> i) & 1)
			now = p[now][i];
	return now;
}

inline int lca (int x, int y) {
	if (h[x] > h[y])
		swap (x, y);
	y = gp (y, h[y] - h[x]);
	if (x == y)
		return x;
	for (int i = dd - 1; i >= 0; --i)
		if (p[x][i] != p[y][i])
			x = p[x][i], y = p[y][i];
	x = p[x][0];
	return x;
}

int main () {
	#ifndef ONLINE_JUDGE	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);

	scanf ("%d", &n);
	//cin >> n;
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		g[x].push_back (y);
		g[y].push_back (x);
	}

	dfs (1, 1);

	scanf ("%d", &m);
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		int root = lca (x, y), pathlen = h[y] - h[root] + h[x] - h[root];
		if (x == y) {
			//cerr << "case 1";
			printf ("%d", n);
			//cout << n;
		}
		else if (pathlen & 1) {
			//cerr << "case 2";
			printf ("0");
			//cout << 0;
		}
		else {
			if (h[y] == h[x]) {
				//cerr << "case 3";
				printf ("%d", n - sz[gp (x, h[x] - h[root] - 1)] - sz[gp (y, h[y] - h[root] - 1)]);
				//cout << n - sz[gp (x, h[x] - h[root] - 1)] - sz[gp (y, h[y] - h[root] - 1)];
			}
			else if (h[y] > h[x]) {
				//cerr << "case 4, ";
				printf ("%d", sz[gp (y, pathlen / 2)] - sz[gp (y, pathlen / 2 - 1)]);
				//cout << sz[gp (y, pathlen / 2)] - sz[gp (y, pathlen / 2 - 1)];
			}
			else {
				//cerr << "case 5";
				printf ("%d", sz[gp (x, pathlen / 2)] - sz[gp (x, pathlen / 2 - 1)]);
				//cout << sz[gp (x, pathlen / 2)] - sz[gp (x, pathlen / 2 - 1)];
			}
		}
		putchar ('\n');
		//cerr << "\n";
	}

	return 0;
}