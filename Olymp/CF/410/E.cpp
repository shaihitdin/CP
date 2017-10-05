#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;

vector <int> g[N], top;
int n_;
int ans[N];

inline void dfs (int v) {
	for (auto to : g[v]) {
		dfs (to);
	}
	top.push_back (v);
	//ans[v] = n_--;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;
	n_ = n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x == -1) {
			ans[i] = n_--;
		} else {
			g[i].push_back (x);
			cerr << i << " " << x << "\n";
		}
	}

	for (int i = n; i >= 1; --i) {
		if (!ans[i])
			dfs (i);
	}
	
	reverse (top.begin (), top.end ());
/*
	for (auto it : top)
		if (!ans[it])
			ans[it] = n_--;
*/
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";	

	return 0;
}