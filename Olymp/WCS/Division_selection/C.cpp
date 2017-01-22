#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

map <int, int> cc;
int u[N];
vector <int> tg[N];

inline bool dfs (int v) {
	if (u[v] == 2)
		return 1;
	if (u[v] == 1)
		return 0;
	u[v] = 2;
	for (auto to : tg[v])
		if (dfs (to))
			return 1;
	u[v] = 1;
	return 0;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector <int> g[n + 1];
		cc.clear ();
		for (int i = 1; i <= n; ++i) {
			int len;
			cin >> len;
			for (int j = 1; j <= len; ++j) {
				int x;
				cin >> x;
				g[i].emplace_back (x);
				cc[x] = 0;
			}
		}
		int scs = 0;
		for (auto &it : cc) {
			it.second = ++scs;
		}
		for (int i = 0; i <= scs; ++i)
			tg[i].clear ();
		for (int i = 1; i <= n; ++i)
			for (int &j : g[i])
				j = cc[j];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < g[i].size (); ++j)
				tg[g[i][j - 1]].emplace_back (g[i][j]);
		}
		for (int i = 1; i <= scs; ++i)
			u[i] = 0;
		bool flag = 0;
		for (int i = 1; i <= scs && !flag; ++i)
			flag |= dfs (i);
		if (flag) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}	
	
	return 0;
}