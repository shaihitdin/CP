#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

int p[N], len[N];
int color[N], st[N], stq, enq;
vector <int> g[N];

inline int gp (const int &v) {
	return p[v] == v ? v : p[v] = gp (p[v]);
}

inline void Merge (int a, int b) {
	a = gp (a);
	b = gp (b);
	if (rand () & 1)
		p[a] = b;
	else
		p[b] = a;
}

inline void dfs (int v) {
	v = gp (v);
	len[v] = 1;
	for (int &to : g[v]) {
		to = gp (to);
		if (!len[to])
			dfs (to);
		len[v] = max (len[v], len[to] + 1);
	}
}


int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	srand (228);
	int n, m, k;
	scanf ("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= m; ++i)
		p[i] = i;

	for (int i = 1; i <= k; ++i) {
		int a, b;
		char action;
		scanf ("%d%c%d", &a, &action, &b);
		if (action == '=')
			Merge (a, b);
		else
			g[b].push_back (a);
	}
	
	for (int i = 1; i <= m; ++i)
		if (gp (i) != i)
			for (int to : g[i])
				g[gp (i)].push_back (gp (to));

	for (int i = 1; i <= m; ++i)
		if (!len[gp (i)])
			dfs (gp (i));
	for (int i = 1; i <= m; ++i) {
		int v = gp (i);	
		assert (len[v] <= n);
		if (len[v] == n) {
			st[++enq] = v;
			color[v] = n;
		}
	}
	while (stq < enq) {
		int v = st[++stq];
		for (int &to : g[v]) {
			to = gp (to);
			if (!color[to]) {
			    color[to] = len[to];
				st[++enq] = to;
			}
		}
	}
	
	for (int i = 1; i <= m; ++i)
		if (!color[gp (i)])
			puts ("?");
		else
			printf ("K%d\n", color[gp (i)]);
	return 0;
}