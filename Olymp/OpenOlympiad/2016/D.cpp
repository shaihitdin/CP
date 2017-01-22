#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;

int v_cnt, num;
int p[N];
vector <int> gx[N], gy[N], a[N], numx[N], numy[N], comp[N];
vector <int> g[N];

inline int get_p (int x) {
	return x == p[x] ? x : p[x] = get_p (p[x]);
}

inline void Merge (int x, int y) {
	x = get_p (x), y = get_p (y);
	if ((++num) % 3 == 0)
		p[x] = y;
	else
		p[y] = x;
}

bool u[N];
int ans[N];

inline void dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g[v]) {
		dfs (to);
		ans[v] = max (ans[v], ans[to]);
	}
	++ans[v];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		a[i].resize (m + 1), comp[i].resize (m + 1);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			gx[i].emplace_back (a[i][j]);
			gy[j].emplace_back (a[i][j]);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		sort (gx[i].begin (), gx[i].end ()), gx[i].resize (unique (gx[i].begin (), gx[i].end ()) - gx[i].begin ());	
		numx[i].resize (gx[i].size ());
	}
	for (int i = 1; i <= m; ++i) {
		sort (gy[i].begin (), gy[i].end ()), gy[i].resize (unique (gy[i].begin (), gy[i].end ()) - gy[i].begin ());
		numy[i].resize (gy[i].size ());
	}	

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			comp[i][j] = ++v_cnt, numx[i][lower_bound (gx[i].begin (), gx[i].end (), a[i][j]) - gx[i].begin ()] = numy[j][lower_bound (gy[j].begin (), gy[j].end (), a[i][j]) - gy[j].begin ()] = v_cnt;
	
	for (int i = 1; i <= v_cnt; ++i)
		p[i] = i;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			Merge (comp[i][j], numx[i][lower_bound (gx[i].begin (), gx[i].end (), a[i][j]) - gx[i].begin ()]);
			Merge (comp[i][j], numy[j][lower_bound (gy[j].begin (), gy[j].end (), a[i][j]) - gy[j].begin ()]);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int pos = lower_bound (gx[i].begin (), gx[i].end (), a[i][j]) - gx[i].begin () - 1;
			if (pos != -1)
				g[get_p (comp[i][j])].emplace_back (get_p (numx[i][pos]));
			pos = lower_bound (gy[j].begin (), gy[j].end (), a[i][j]) - gy[j].begin () - 1;
			if (pos != -1)
				g[get_p (comp[i][j])].emplace_back (get_p (numy[j][pos]));
		}
	}
	
	for (int i = 1; i <= v_cnt; ++i)
		dfs (get_p (i));
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[get_p (comp[i][j])] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}