#include <bits/stdc++.h>

using namespace std;

struct edge {
	int to, cap, flow;
};

const int oo = 1e9, N = 1e6 + 100;

vector <edge> e;
int v_cnt;
int s, t;
long long flow;
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
	limit = 1 << 30;
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

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char a[110][110];
int v[110][110];

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cnt += a[i][j] == '#';
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			v[i][j] = ++v_cnt;
		}
	}
	
	s = ++v_cnt;
	t = ++v_cnt;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#')
				continue;
			if ((i & 1) ^ (j & 1)) {
				add_edge (s, v[i][j], 1);
				for (int k = 0; k < 4; ++k) {
					int ni = i + dx[k], nj = j + dy[k];
					if (inside (ni, nj) && a[ni][nj] != '#')
						add_edge (v[i][j], v[ni][nj], 1);
				}
			} else {
				add_edge (v[i][j], t, 1);
			}
		}
	}	

	FordFulkerson ();
	
	if (flow * 2 + cnt == n * m) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}