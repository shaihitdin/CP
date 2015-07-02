#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 3e4, M = 4e5;

typedef long long ll;

struct edge {
	int to, flow, cap;
};

edge e[M];
int sz;
int s, f;
int limit;
ll ans;

int n, m;

vector <int> g[N];

inline void add_edge (const int &from, const int &to, const int &cap) {
	edge e1 = {to, 0, cap}, e2 = {from, 0, 0};
	e[sz] = e1;
	g[from].push_back (sz++);
	e[sz] = e2;
	g[to].push_back (sz++);
}


int st[N + N], stq, enq;
int d[N];
int ptr[N];

inline bool bfs () {
	stq = enq = 0;
	st[++enq] = s;
	memset (d, 0, sizeof (d));
	memset (ptr, 0, sizeof (ptr));
	d[s] = 1;
	while (stq < enq) {
		int v = st[++stq];
		for (auto id : g[v]) {
			int to = e[id].to, flow = e[id].flow, cap = e[id].cap;
			if (!d[to] && flow <= cap - limit) {
				st[++enq] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[f] != 0;
}

inline int dfs (const int &v, const int &push) {
	if (push <= 0)
		return 0;
	if (v == f)
		return push;
	for (; ptr[v] < (int)g[v].size (); ++ptr[v]) {
		int id = g[v][ptr[v]];
		int to = e[id].to, flow = e[id].flow, cap = e[id].cap;
		if (d[to] == d[v] + 1 && flow <= cap - limit) {
			int pushed = dfs (to, limit);
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
	while (bfs ()) {
		while (1) {
			int res = dfs (s, limit);
			if (!res)
				break;
			ans += res;
		}
	}
}


int main () {
	//#ifdef LOCAL
	freopen ("flow2.in", "r", stdin);
	freopen ("flow2.out", "w", stdout);
	//#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y, cap;
		cin >> x >> y >> cap;
		add_edge (x, y, cap);
	}

	/// cin >> s >> f;
	s = 1, f = n;

	
	for (limit = (1 << 30); limit; limit >>= 1)
		dinitz ();
	
	cout << ans;
	
	return 0;
}