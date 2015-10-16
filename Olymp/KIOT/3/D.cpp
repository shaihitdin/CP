#include <bits/stdc++.h>

using namespace std;

const int N = 5100;

int cnt[N];
vector <int> g[N];
int n;

inline void dfs (const int &v, const int &p) {
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs (to, v);
		cnt[v] += cnt[to];
	}
	++cnt[v];
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
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	int mx = 0;
	
	bool can[N];
	memset (can, 0, sizeof (can));


	for (int root = 1; root <= n; ++root) {
		memset (cnt, 0, sizeof (cnt));
		dfs (root, 0);
		
		bool reach[N];
		memset (reach, 0, sizeof (reach));
		
		reach[0] = 1;

		for (auto to : g[root]) {
			for (int i = n; i >= 0; --i) {
				reach[cnt[to] + i] |= reach[i];
			}
		}
		for (int i = 1; i <= n; ++i)
			can[i] |= reach[i];
	}
	

	int ans = 0;

	for (int i = 1; i < n - 1; ++i)
		ans += can[i];
	
	cout << ans << "\n";
	
	for (int i = 1; i < n - 1; ++i) {
		if (can[i]) {
			cout << i << " " << n - 1 - i << "\n";
		}
	}
	
	return 0;
}