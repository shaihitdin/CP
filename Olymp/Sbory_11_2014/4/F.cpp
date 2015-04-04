#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int cost[2], n, x, t;
vector <int> g[1001];

inline int dfs (int v, bool flag) {
	int res = cost[flag];
	for (int i = 0; i < g[v].size(); ++i) {
		res += (dfs (g[v][i], !flag) );
	}
	//cerr << v << "\n";
	return res;
}
int main () {
	freopen ("gifts.in", "r", stdin);
	freopen ("gifts.out", "w", stdout);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		printf ("Scenario #%d:\n",test);
		scanf ("%d%d", &cost[0], &cost[1]);
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			scanf ("%d",&x);
			cerr << x << " ";
			g[x].push_back(i);
		}
		cerr << "\n";
		printf ("%d\n\n", min (dfs (0, 0), dfs (0, 1) ) );
	}
	return 0;
}