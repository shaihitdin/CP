#include <bits/stdc++.h>

using namespace std;

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
	limit = 1 << 11;
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

int main () {

	freopen ("evacuation.in", "r", stdin);
	freopen ("evacuation.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> k >> tim;
	
	if (n == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		v[i].resize (tim + 1);
		for (int j = 0; j <= tim; ++j)
			v[i][j] = ++v_cnt;
	}
	
	for (int i = 1; i <= m; ++i) {
		int from, to, len, cap;
		cin >> from >> to >> len >> cap;
		for (int j = 0; j + len <= tim; ++j)
			add_edge (v[from][j], v[to][j + len], cap);
	}
	
	s = v[1][0];

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < tim; ++j)
			add_edge (v[i][j], v[i][j + 1], oo);
	
	t = ++v_cnt;
	
	for (int j = 0; j <= tim; ++j)
		add_edge (v[n][j], t, oo);
	
	valid[s] = 1;
	valid[t] = 1;	
	
	for (int i = 0; i <= tim; ++i) {
		for (int j = 1; j <= n; ++j)
			valid[v[j][i]] = 1;
		FordFulkerson ();		
		if (flow >= k) {
			cout << i;
			return 0;
		}
	}
	
	
	cout << k - flow;
	
	return 0;
}
