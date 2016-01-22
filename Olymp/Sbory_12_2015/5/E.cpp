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

int n, m;

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int xa, xb, xc, ya, yb, yc;
char a[110][110];
int in[110][110], out[110][110];

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
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			in[i][j] = ++v_cnt, out[i][j] = ++v_cnt;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 'A') {
				xa = i, ya = j;
			} else if (a[i][j] == 'B') {
				xb = i, yb = j;
			} else if (a[i][j] == 'C') {
				xc = i, yc = j;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 'A' || a[i][j] == 'C' || a[i][j] == '#')
				add_edge (in[i][j], out[i][j], 0);
			else
				add_edge (in[i][j], out[i][j], 1);
		}
	}
	
	s = ++v_cnt;
	t = ++v_cnt;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 0; k < 4; ++k) {
				int ni = i + dx[k], nj = j + dy[k];
				if (inside (ni, nj))
					add_edge (out[i][j], in[ni][nj], 1);
			}
		}
	}
	
	add_edge (s, out[xb][yb], 2);
	add_edge (in[xa][ya], t, 1);
	add_edge (in[xc][yc], t, 1);
	
	FordFulkerson ();
	
	if (flow == 2)
		cout << "Yes";
	else
		cout << "No";
		
	return 0;
}
