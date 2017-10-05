#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

bool u[N];

vector <int> top;
vector <int> g[N], ans[N];
int n, m, k;

inline void dfs (int v, int p) {
	if (u[v])
		return;
	u[v] = 1;
	top.push_back (v);
	for (auto to : g[v])
		dfs (to, v);
	if (v != 1)
		top.push_back (p);
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}

	dfs (1, 0);
	
	int step = (n + n + k - 1) / k;

	for (int i = 0, j = 1; i < top.size (); ++i) {
		if (ans[j].size () == step)
			++j;
		ans[j].push_back (top[i]);
	}
	
	for (int i = 1; i <= k; ++i) {
		if (!ans[i].size ()) {
			ans[i].push_back (1);
		}
		cout << ans[i].size () << " ";
		for (int j : ans[i]) {
			cout << j << " ";
		}
		cout << "\n";
	}
	
	return 0;
}