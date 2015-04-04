#include <bits/stdc++.h>

using namespace std;

inline char readChar() {
	char c = getchar();
	while (c <= 32)
		c = getchar();
	return c;
}

inline int readInt() {
	int s = 0, c = readChar(), x = 0;
	if (c == '-')
		s = 1, c = getchar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return s ? -x : x;
}

const int N = 1e5 + 10, K = 110;

bool u[N];
vector <int> g[N], topsort;
int n, m, a[K];

inline void topsort_dfs (const int &v) {
	u[v] = 1;
	for (int to : g[v])
		if (!u[to])
			topsort_dfs (to);
	topsort.push_back (v);
}

int can[N]; // go till the end in : 0 - even move, 1 - odd move.


inline void dfs_game (const int &v) {
	u[v] = 1;

	if (!g[v].size())
		can[v] = 0;

	for (int to : g[v])
		if (!u[to])
			dfs_game (to);

	for (int to : g[v])
		if (can[to] == 0)
			can[v] = 1;
	
	if (can[v] == 2)
		can[v] = 0;
}


int main () {
	
	freopen ("1.in", "r", stdin);
	freopen ("1.out", "w", stdout);

	n = readInt();
	m = readInt();

	for (int i = 1; i <= m; ++i) {
		int x, y;
		x = readInt();
		y = readInt();
		g[x].push_back (y);
	}

	for (int i = 1; i <= n; ++i)
		if (!u[i])
			topsort_dfs (i);

	reverse (topsort.begin(), topsort.end());
	for (int i = 1; i <= n; ++i)
		can[i] = 2;
	memset (u, 0, sizeof (u));
	
	for (int i : topsort)
		if (!u[i])
			dfs_game (i);
		
	int q = readInt();

	++q;
	
	while (--q) {
		int k = readInt();
		for (int i = 1; i <= k; ++i)
			a[i] = readInt();
		int res = 0;
		for (int i = 1; i <= k; ++i)
			res ^= can[a[i]];
		puts (res ? "Bumi" : "Iroh");
	}


	return 0;
}