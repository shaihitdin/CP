#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = (1e5) + 1;
vector <pair <int, int> > g[N];
vector <pair <int, int> >
inline void dfs (const int &v) {
	u[v] = 1;

}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		g[x].push_back({y, i});
		g[y].push_back({x, i});

	}
	for (int i = 1; i <= n; ++i) {
		if (!u[i])
			dfs(i);
	}
	return 0;
}