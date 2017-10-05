#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;

vector <int> g[N], top;
int n_;
int ans[N], a[N];
bool used[N];

inline void dfs (int v) {
	if (used[v])	return;
	used[v] = 1;
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
	
	int lst = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == -1)
			lst = i;
	}

	for (int i = 1; i <= n; ++i) {
		if (a[i] != -1)
			g[i].push_back (lst);
	}	
	
	for (int i = lst - 1; i >= 1; --i) {
		if (a[i] == -1) {
			g[lst].push_back (i);
			lst = i;
		}
	}

	lst = 1;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1)
			continue;
		while (lst < a[i]) {
			if (a[lst] != -1 && lst != i)
				g[lst].push_back (i);
			++lst;
		}
		g[i].push_back (a[i]);
	}
	
	for (int i = 1; i <= n; ++i)
		dfs (i);
	
	reverse (top.begin (), top.end ());

	for (int i = 0; i < top.size (); ++i)
		ans[top[i]] = i + 1;	

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";

	return 0;
}