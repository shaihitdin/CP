#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

vector <int> g[N];

bool u[N];

int n;

inline int dfs (const int &v) {
	u[v] = 1;
	int res = 0;
	for (auto to : g[v])
		if (!u[to])
			res += dfs (to);
	if (!res)
		return 1;
	return res;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	
	cerr << "OK";

	int res = dfs (1);
	
	if (g[1].size () == 1)
		cout << res;
	else
		cout << res - 1;

	return 0;
}