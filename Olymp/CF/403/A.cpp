#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair

const int N = 2e5 + 100;

vector <int> g[N];
int ans[N];
int n;

inline void dfs (int v, int p) {
	for (int i = 0, j = 1; i < g[v].size (); ++i, ++j) {
		while (j == ans[v] || j == ans[p])	++j;
		int to = g[v][i];
	   	if (to == p) {
	   		--j;
	   		continue;
	   	}
		ans[to] = j;
		dfs (to, v);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}

	int mxpos = 1;
	
	for (int i = 1; i <= n; ++i) {
		if (g[i].size () > g[mxpos].size ())
			mxpos = i;
	}
	
	ans[mxpos] = 1;
	dfs (mxpos, 0);
	
	cout << g[mxpos].size () + 1 << "\n";

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	
	return 0;
}