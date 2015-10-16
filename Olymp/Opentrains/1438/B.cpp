#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m;
vector <int> g[N], g_rev[N], top, c_col[N];
int a[N * 10];
int col[N];
bool u[N];

inline void dfs (const int &v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g[v])
		dfs (to);
	top.emplace_back (v);
}

int cnt;

inline void rev_dfs (const int &v, int x = -1) {
	if (col[v])
		return;
	if (x == -1)
		x = ++cnt;
	col[v] = x;
	for (auto to : g_rev[v]) {
		rev_dfs (to, x);
	}
	c_col[x].emplace_back (v);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> m >> n;

	for (int i = 1; i <= m; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)
			cin >> a[j];
		for (int j = 2; j <= k; ++j) {
			g[a[j - 1]].emplace_back (a[j]);
			g_rev[a[j]].emplace_back (a[j - 1]);
	     }
	}

	for (int i = 1; i <= n; ++i)
		dfs (i);

	reverse (top.begin (), top.end ());
	
	for (auto v : top)
		rev_dfs (v);
	
	
	cout << cnt << "\n";

	for (int i = 1; i <= cnt; ++i) {
		cout << c_col[i].size () << " ";
		for (auto v : c_col[i])
			cout << v << " ";
		cout << "\n";
	}
	
	return 0;
}