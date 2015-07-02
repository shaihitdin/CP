#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 1e4, M = 1e5;

typedef long long ll;

int n, m, sz;

int d[N], s, f, nn;

vector <int> v[N];

int q[N], stq, enq;
int push, pos[N], ans;

int h[N], ve[N];

int c[100][100], check[100][100];

struct edge {
	int y, cap, flow;
} e[M];

inline void add_edge(const int &x, const int &y, const int &cap) {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
	v[x].push_back (sz);
	e[sz++] = e1;
	v[y].push_back (sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while (stq < enq) {
		int x = q[++stq];
		for (int i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			if (d[to] == 0 && e[id].flow < e[id].cap)
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
			int pushed = dfs (to, min (1, e[id].cap - e[id].flow));
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
	while (bfs ()) {
		while (true) {
			int push = dfs (s, 1);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	s = ++nn;
	f = ++nn;

	for (int i = 1; i <= n; ++i) {
		int cap;
		cin >> cap;
		h[i] = ++nn;
		add_edge (s, h[i], cap);
	}
	
	for (int i = 1; i <= m; ++i) {
		int cap;
		cin >> cap;
		ve[i] = ++nn;
		add_edge (ve[i], f, cap);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			c[i][j] = ++nn;
			add_edge (h[i], c[i][j], 1);
			add_edge (c[i][j], ve[j], 1);
			check[i][j] = sz - 2;
		}
	}

	dinitz();

	cerr << ans << " ";

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (e[check[i][j]].flow)
				cout << "*";
			else
				cout << ".";
		}
		cout << "\n";
	}		

return 0;
}