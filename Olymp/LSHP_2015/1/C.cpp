#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int n, to[N], c[N], in[N];
int in_c[N];
int ans;

int cycle_cnt;

vector <int> circle[N];

vector <int> top_sort;

char u[N];

int balance[N];
int p[N];


inline void get_cycle (const int &v, const int &cycle_num) {
	for (int u = v, need = 0; u != v || !need; u = p[u], need = 1)
		in_c[u] = cycle_num, circle[cycle_num].push_back (u);
	reverse (circle[cycle_num].begin (), circle[cycle_num].end ());
}

inline void dfs (const int &v) {
	u[v] = 1;
	if (!u[to[v]]) {
		p[to[v]] = v;
		dfs (to[v]);
	}
	else if (u[to[v]] == 1) {
		p[to[v]] = v;
		get_cycle (to[v], ++cycle_cnt);
	}
	u[v] = 2;
}

inline void top_sort_f (const int &v) {
	u[v] = 1;
	if (!u[to[v]] && !in_c[to[v]])
		top_sort_f (to[v]);
	top_sort.push_back (v);
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> to[i] >> c[i];
		++in[to[i]];
	}
	
	for (int i = 1; i <= n; ++i)
		if (!u[i])
			dfs (i);

	memset (u, 0, sizeof (u));
		
	for (int i = 1; i <= n; ++i) {
		if (!u[i] && !in_c[i])
			top_sort_f (i);
	}

	reverse (top_sort.begin (), top_sort.end ());
	
	for (auto v : top_sort) {
		ans += max (0, c[v] - balance[v]);
		balance[v] = c[v];
		balance[to[v]] += c[v];
		balance[to[v]] = min (balance[to[v]], c[to[v]]);
	}

	for (int i = 1; i <= cycle_cnt; ++i) {

		bool flag = 0;
		for (auto it : circle[i])
			if (c[it] - balance[it] != c[circle[i][0]] - balance[circle[i][0]])
				flag = 1;
		
		if (!flag) {
			for (auto it : circle[i]) {
				ans += max (0, c[it] - balance[it]);
				balance[it] = c[it];
				balance[to[it]] += balance[it];
			}
			continue;
		}
		
		int v = circle[i][0];
		v = to[v];
		while (c[v] - balance[v] >= c[to[v]] - balance[to[v]])
			v = to[v];
		int f_p = v;

		for (int need = 0; f_p != v || !need; v = to[v], need = 1) {
			ans += max (0, c[v] - balance[v]);
			balance[v] = c[v];
			balance[to[v]] += balance[v];
		}
	}
	
	cout << ans;
	
	return 0;
}