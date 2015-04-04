#include <iostream>
#include <stdio.h>
using namespace std;
const int N = (1e5) + 1;
struct edge {
	int to, cost, t;
};
vector <edge> g[N];
bool u[N];
int sum[N];
inline int dfs (const int &v, const int &pe) {
	u[v] = 1;
	tin[v] = ++timer;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!u[g[v][i].to]) {
			sum[v] += dfs (g[v][i].to, g[v][i].cost);
		}
	}
	tout[v] = ++timer;
	return sum[v] + (tout[v] - tin[v]) * pe;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d%d%d", &x, &y, &cost, &t);
		g[x].push_back({y, cost, t});
	}
	dfs (1, 0);

	return 0;
}