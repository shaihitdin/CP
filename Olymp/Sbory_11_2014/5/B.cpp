#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
struct edge {
	int y, t, c;
};
const int N = 101, inf = 1000000009;
vector <edge> g[N];
int d[N][1001];
int y, t, c, n, m, s, x, ans = inf;
int main () {
	freopen ("daneel.in", "r", stdin);
	freopen ("daneel.out" ,"w", stdout);
	scanf ("%d%d", &n, &m);
	scanf ("%d", &s);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &x, &y, &t, &c);
		g[x].push_back({y,t,c});
		g[y].push_back({x,t,c});
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= 1000; ++j)
			d[i][j] = inf;
	d[1][0] = 0;
	for (int i = 0; i <= s; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[j][(i) % 1000] == inf)	continue;
			if (j == n) {
				ans = min (ans, d[j][i % 1000]);
			}
			for (auto to : g[j]) {
				d[to.y][(i + to.c) % 1000] = min (d[to.y][(i + to.c) % 1000], d[j][(i) % 1000] + to.t);
			}
			d[j][i % 1000] = inf;
		}
	}
	if (ans != inf)
		printf ("%d", ans);
	else
		printf ("-1");
	return 0;
}