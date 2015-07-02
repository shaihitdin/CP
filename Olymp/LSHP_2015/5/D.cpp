#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 3e4, M = 4e5, sN = 70;

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


#define str can

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


int pos_to_vertex[sN][sN][sN], v_cnt;
int pos_in_str[N];
int p, h, w;
string S[sN][sN];
int nxt[sN][sN][sN];
int alpha_v[256];

int main () {
	//#ifdef LOCAL
	freopen ("ripper.in", "r", stdin);
	freopen ("ripper.out", "w", stdout);
	//#endif

	ios_base :: sync_with_stdio (0);

	cin >> p >> h >> w;

	s = ++v_cnt;
	f = ++v_cnt;
	
	for (int i = 1; i <= p; ++i) {
		for (int j = 1; j <= h; ++j) {
			cin >> S[i][j];
			S[i][j] = '#' + S[i][j];
			S[i][j].resize (w + 1);
		}
		for (int j = 1; j <= h; ++j)
			for (int k = 1; k <= w; ++k)
				pos_to_vertex[i][j][k] = ++v_cnt;
	}
	
	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= h; ++j)
			for (int k = 1; k <= w; ++k)
				add_edge (s, pos_to_vertex[i][j][k], 1);
	
	for (int i = 1; i <= p + 1; ++i)
		for (int j = 1; j <= h; ++j)
			S[i][j].resize (w + 1);

	for (int i = 1; i <= p; i += 2) {
		for (int j = 1; j <= h; ++j) {
			for (int k = 1; k <= w; ++k) {
				nxt[i][j][k] = ++v_cnt;
				nxt[i + 1][j][k] = nxt[i][j][k];
				add_edge (pos_to_vertex[i][j][k], nxt[i][j][k], 1);
				add_edge (pos_to_vertex[i + 1][j][k], nxt[i][j][k], 1);
			}
		}
	}
	
	for (int i = 'A'; i <= 'Z'; ++i)
		alpha_v[i] = ++v_cnt;
	
	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= h; ++j)
			for (int k = 1; k <= w; ++k)
				if (S[i][j][k] > 0)
					add_edge (nxt[i][j][k], alpha_v[S[i][j][k]], 1);
	
	string t;

	cin >> t;

	for (int i = 0; i < t.size (); ++i) {
		add_edge (alpha_v[t[i]], ++v_cnt, 1);
		add_edge (v_cnt, f, 1);
	}
		
	dinitz ();
			
	if (ans == t.size ()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
	return 0;
}