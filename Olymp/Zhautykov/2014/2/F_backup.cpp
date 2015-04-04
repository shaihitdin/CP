#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int N = (1e5) + 1, M = 8 * N;
int s, f, stq, enq;
vector <int> g[N];
struct edge {
	int y, cap, flow;
};
edge e[N];
int ans;
long long result;
int n, m, k, x, y;
int sz, l, r, st[M], d[N], pos[N];
inline void add_edge (const int &x, const int &y, const int &cap) {
	edge e1, e2;
	e1 = {y, cap, 0};
	e2 = {x, 0, 0};
	g[x].push_back(sz);
	e[sz++] = e1;
	g[y].push_back(sz);
	e[sz++] = e2;
}
inline bool bfs () {
	stq = enq = 0;
	st[enq++] = s;
	memset (d, 0, sizeof(d) );
	memset (pos, 0, sizeof(d) );
	d[s] = 1;
	while (stq != enq) {
		int v = st[stq++];
		for (auto id : g[v]) {
			int to = e[id].y;
			if ( ( (to < n + 1 || to > n + m) || (n + 1 <= to && to <= n + m && (l <= to && to <= r) ) ) && !d[to] && e[id].cap > e[id].flow) {
				d[to] = d[v] + 1;
				st[enq++] = to;
			} 
		}
	}
	return d[f] != 0;
}
inline int dfs (const int &v, const int &flow) {
	if (!flow)
		return 0;
	if (v == f)
		return flow;
	for (; pos[v] < g[v].size(); ++pos[v]) {
		int id = g[v][pos[v]];
		int to = e[id].y;
		if (d[to] == d[v] + 1) {
			int pushed = dfs (to, min (flow, e[id].cap - e[id].flow) );
			if (pushed) {
				e[id].flow += pushed;
				e[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}
inline void dinitz () {
	while (bfs()) {
		while (1) {
		    int push = dfs(s, (int)(1e9) + 1);
			if (!push)
				break;
			ans += push; 
		}	
	}
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	swap (n, m);
	for (int i = 1; i <= k; ++i) {
		scanf ("%d%d", &x, &y);
		swap (x, y);
		add_edge (x, y + n, 1);
	}
	s = n + m + 1;
	f = n + m + 2;	
	for (int i = 1; i <= n; ++i)
		add_edge (s, i, 1);
	for (int i = n + 1; i <= n + m; ++i)
		add_edge (i, f, 1);
	for (l = n + 1; l + n - 1 <= n + m; ++l) {
		for (r = l + n - 1; r <= n + m; ++r) {
			dinitz();
			if (ans == n) {
				result += (n + m - r + 1);
				break;
			}
		}
		for (int i = 0; i < sz; ++i)
			e[i].flow = 0;
		ans = 0;
	}
	printf ("%d", result);
	return 0;
}