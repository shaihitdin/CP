#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100, bpr = 1e9 + 7;

typedef long long ll;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline void ms (int &x, int y) {
	x -= y;
	if (x <= 0)
		x += bpr;
}

int t_cnt[N], t_sum[N];
vector <int> g[N];

struct node {
	int sum1, sum2, to_p;
}

inline void push (int v) {
	add (t[v].sum2, (t[v].sum1 * 1ll * t[v].to_p) % bpr);
	if (v < sz) {
		t[v + v].to_p += t[v].to_p;
		t[v + v + 1].to_p += 
	}
}


inline void upd (int v, int Tl, int Tr, int l, int r, int sum_times) {
	
}


int val[N], m, q_type[N], q1[N], q2[N], n;
int tin[N], tout[N], timer;

inline void dfs (int v) {
	tin[v] = ++timer;
	for (int to : g[v])
		dfs (to);
	tout[v] = timer;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> val[1] >> m;

	n = 1;
	
	for (int i = 1; i <= m; ++i) {
		cin >> q_type[i];
		if (q_type[i] == 1) {
			cin >> q1[i] >> q2[i];
			g[q1[i]].emplace_back (++n);
			val[n] = q2[i];
		} else {
			cin >> q1[i];
		}
	}

	dfs (1);
	
	int now_n = 1;

	upd (t_cnt, tin[1], 1);
	upd (t_sum, tin[1], val[1]);
	
	for (int i = 1; i <= m; ++i) {
		if (q_type[i] == 1) {
			upd (t_cnt, tin[++now_n], 1);
			upd (t_sum, tin[now_n], val[now_n]);
		} else {
			ll res = get (t_sum, tin[q1[i]], tout[q1[i]]);
			cerr << res << " ";
			res = (res * get (t_cnt, tin[q1[i]], tout[q1[i]])) % bpr;
			cerr << get (t_cnt, tin[q1[i]], tout[q1[i]]) << " ";
			cout << res << "\n";
		}
	}

	return 0;
}