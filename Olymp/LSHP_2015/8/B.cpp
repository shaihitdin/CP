#include <bits/stdc++.h>

using namespace std;

const int N = 2200;

vector <pair <int, int> > g[N];

bool u[N];
bool bridge[N * N];

int tin[N], fup[N], timer;

int p[N];

inline void dfs (int v, const int &pv) {
    tin[v] = ++timer;
    fup[v] = timer;
    for (int i = 0; i < g[v].size(); ++i) {
    	if(g[v][i].first == pv)
    		continue;
    	int to = g[v][i].first;
    	if (tin[to]) {
    		fup[v] = min (tin[to], fup[v]);
    	} else {
    		dfs (to, v);
    		if (tin[v] <= fup[to])
    			bridge[g[v][i].second] = 1;
    		fup[v] = min (fup[v], fup[to]);
    	}
    }
}

int clrsz;

int col[N];

inline void color (int v, int c) {
	u[v] = 1;
	col[v] = c;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!u[g[v][i].first]) {
			if (bridge[g[v][i].second])
				color (g[v][i].first, ++clrsz);
			else
				color (g[v][i].first, c);
		}	
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	
	cin >> n;

	int edge_cnt = 0;
	
	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			x += n;
			g[i].push_back (make_pair (x, ++edge_cnt));
			g[x].push_back (make_pair (i, edge_cnt));
		}
	}
	
	for (int i = 1; i <= n + n; ++i)
		if (!tin[i])
			dfs (i, -1);

	int clr_sz = 0;
	
	for (int i = 1; i <= n + n; ++i)
		if (!u[i])
			color (i, ++clr_sz);
	
	
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		vector <int> ans;
		if (col[p[i] + n] != col[i])
			goto here;
		for (auto to : g[i]) {
			if (col[to.first] == col[i]) {
				ans.push_back (to.first - n);
				if (to.first - n == p[i])
					p[i] = -1;
			}
		}
		here:;
		if (p[i] != -1)
			ans.push_back (p[i]);
		cout << ans.size () << " ";
		for (auto v : ans)
			cout << v << " ";
		cout << "\n";
	}
	
	return 0;
}