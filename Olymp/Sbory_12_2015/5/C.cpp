#include <bits/stdc++.h>

using namespace std;

struct edge {
	int to, cap, flow;
};

const int oo = 1e9, N = 1e6 + 100;

vector <edge> e;
int v_cnt;
int s, t;
int flow;
vector <int> g[N];
int u[N], timer;
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
	limit = 1;
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

int n, k;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;

	v_cnt = n;

	s = 1;

	for (int i = 1; i <= k; ++i) {
		int a, b;
		cin >> a >> b;
		add_edge (a, b, 1);
		add_edge (b, a, 1);
	}
	
	int ans = oo;
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < e.size (); ++j)
			e[j].flow = 0;
		flow = 0;
		t = i;
		FordFulkerson ();
		ans = min (ans, flow);
	}
	
	cout << ans;
	
	return 0;
}
