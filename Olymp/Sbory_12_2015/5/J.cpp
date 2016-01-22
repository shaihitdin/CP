#include <bits/stdc++.h>

using namespace std;

struct edge {
	int to, cap, flow, cost;
};

const int oo = 1e9, N = 1100;

vector <edge> e;
int v_cnt;
int s, t;
int flow;
int flow_cost;
vector <int> g[N], g2[N];
int u[N], timer;
int limit;
int d[N], phi[N];
int p[N], pe[N];

inline void add_edge (int from, int to, int cap, int cost) {
	g[from].push_back (e.size ());
	e.push_back ({to, cap, 0, cost});
	g[to].push_back (e.size ());
	e.push_back ({from, 0, 0, -cost});
}

inline bool Dijkstra () {
	set <pair <int, int> > Set;
	for (int i = 1; i <= v_cnt; ++i)
		d[i] = oo;
	d[s] = 0;
	Set.insert (make_pair (d[s], s));
	while (Set.size ()) {
		int v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto id : g[v]) {
			int to = e[id].to;
			if (e[id].flow < e[id].cap && d[to] > d[v] + e[id].cost + phi[v] - phi[to]) {
				Set.erase (make_pair (d[to], to));
				d[to] = d[v] + e[id].cost + phi[v] - phi[to];
				p[to] = v;
				pe[to] = id;
				Set.insert (make_pair (d[to], to));
			}
		}
	}
	for (int i = 1; i <= v_cnt; ++i)
		phi[i] = min (phi[i] + d[i], oo);
	return d[t] != oo;
}

inline void MincostMaxflow () {
	while (Dijkstra ()) {
		for (int v = t; v != s; v = p[v]) {
			++e[pe[v]].flow;
			--e[pe[v] ^ 1].flow;
			flow_cost += e[pe[v]].cost;
		}
		++flow;
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

	v_cnt = n + k;
	s = ++v_cnt;
	t = ++v_cnt;
	
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		add_edge (i, t, x, y);
	}
	
	for (int i = 1; i <= k; ++i) {
		int te;
		cin >> te;
		add_edge (s, i + n, 1, 0);
		while (te--) {
			int x;
			cin >> x;
			add_edge (i + n, x, 1, 0);
		}
	}
	
	MincostMaxflow ();

	if (flow != k) {
		cout << -1;
		return 0;
	}
	
	cout << flow_cost;
	
	return 0;
}
