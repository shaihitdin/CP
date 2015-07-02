#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 501*501, M = 10001*10;
int n, m, sz;
int d[N], s, f;
vector <int> v[N];
int q[N], stq, enq;
int push, pos[N], ans;
int in[N], out[N];
int check_edge[501][501];

struct edge {
	int y, cap, flow;
}e[M];

int limit = 1 << 8;

inline void add_edge (const int &x, const int &y, const int &cap) {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while (stq < enq) {
		int x = q[++stq];
		for (int i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (d[to] == 0 && e[id].flow + limit <= e[id].cap)
			 	d[to] = d[x]+1, q[++enq] = to;
		}
	}
	return d[f] != 0;
}

inline int dfs(const int &x, const int &flow) {
	if (x == f) return flow;
	if (!flow) return 0;
	for (; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x] + 1) { 	
			int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
			if(pushed) {
				e[id].flow += pushed;
				e[id^1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

inline void dinitz() {
	memset(pos, 0, sizeof(pos));
	memset(d, 0, sizeof(d));
	enq = stq = 0;
	while (bfs()) {
		while (true) {
			int push = dfs(s, 1 << 8);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}

int vertex_cnt = 0;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		in[i] = ++vertex_cnt;
		out[i] = ++vertex_cnt;
	}
	
	s = ++vertex_cnt;
	f = ++vertex_cnt;

	int sum2 = 0;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		add_edge (s, in[i], x);
		sum2 += x;
	}
	
	int sum = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			check_edge[i][j] = 2000;
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		add_edge (out[i], f, x);
		sum += x;
	}

	for (int i = 1; i <= n; ++i) {
		add_edge (in[i], out[i], 100);
		check_edge[i][i] = sz - 2;
	}	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		add_edge (in[x], out[y], 100);
		check_edge[x][y] = sz - 2;
		add_edge (in[y], out[x], 100);
		check_edge[y][x] = sz - 2;
	}
	
	for (limit = 1 << 8; limit; limit >>= 1)
		dinitz ();
	
	if (ans != sum || ans != sum2) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << e[check_edge[i][j]].flow << " ";
		cout << "\n";
	}	
	return 0;
}