#include <bits/stdc++.h>

using namespace std;

/*
struct edge {
	int to, cap, flow;
};

const int oo = 1e9, N = 1e6 + 100, sN = 1e4 + 100;


vector <edge> e;
int v_cnt;
int s, t;
int flow;
vector <int> v[sN];
vector <int> g[N];
int u[N], timer;
bool valid[N];
int limit;

inline void add_edge (int from, int to, int cap) {
	g[from].push_back (e.size ());
	e.push_back ({to, cap, 0});
	g[to].push_back (e.size ());
	e.push_back ({from, 0, 0});
}

inline int dfs (int v, int flow = oo) {
	if (v == t)
		return flow;
	if (flow < limit)
		return 0;
	if (u[v] == timer)
		return 0;
	u[v] = timer;
	for (auto id : g[v]) {
		int to = e[id].to;
		if (!valid[to])
			continue;
		
		int to_push = min (flow, e[id].cap - e[id].flow);
		int pushed = dfs (to, to_push);
		if (pushed) {
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

inline void FordFulkerson () {
	limit = 1 << 13;
	while (limit) {
		while (1) {
			++timer;
			int tmp = dfs (s);
			if (!tmp)
				break;
			flow += tmp;
		}
		limit >>= 1;
	}
}

int n, m, k, tim;

*/

const int N = 3e4 + 100;

int n, k;
int a[N], b[N];
int part1, part2;
bool u[N];
vector <int> g[N];

inline void dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	if (v <= n) {
		part1 += a[v];
	} else {
		part2 += b[v - n];
	}
	for (auto to : g[v])
		dfs (to);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}	
	
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y + n);
		g[y + n].emplace_back (x);
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (!u[i]) {
			part1 = 0, part2 = 0;
			dfs (i);
			ans += min (part1, part2);
		}
	}
	
	cout << ans;
	
	return 0;
}
