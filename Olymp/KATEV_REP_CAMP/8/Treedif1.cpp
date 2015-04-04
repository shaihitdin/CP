#include <bits/stdc++.h>

using namespace std;

const int N = 50001;

set <int> root[N];

vector <int> g[N];
int ans[N], n, m;

inline void dfs (const int &v) {
	ans[v] = INT_MAX;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		dfs (to);
		ans[v] = min (ans[v], ans[to]);
		if (root[v].size() < root[to].size())
			swap (root[v], root[to]);
		set <int> :: iterator it, it1;
		for (it = root[to].begin(); it != root[to].end(); ++it) {
			it1 = root[v].lower_bound (*it);
			if (it1 != root[v].end())
				ans[v] = min (ans[v], *it1 - *it);			
			if (it1 != root[v].begin()) {
				--it1;
				ans[v] = min (ans[v], *it - *it1);
			}
		}
		for (it = root[to].begin(); it != root[to].end(); ++it)
			root[v].insert (*it);
	}
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &m);

	for (int i = 2; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		g[x].push_back (i);
	}

	for (int i = n - m + 1; i <= n; ++i) {
	    int x;
		scanf ("%d", &x);
		root[i].insert (x);
	}

	dfs (1);

	for (int i = 1; i <= n - m; ++i)
		printf ("%d ", ans[i]);

	return 0;
}