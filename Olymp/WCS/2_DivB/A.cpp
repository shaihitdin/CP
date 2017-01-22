#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int dp[N][2], up[N][2];
int n;
vector <pair <int, int> > g[N];


int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		int v, k;
		cin >> v >> k;
		g[v].emplace_back (make_pair (i, k));
	}

	for (int i = 1; i <= n; ++i) {
		for (auto to : g[i])
			dp[i][1] += to.second;
	}
	
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (auto to : g[i])
			sum += to.second;
		for (auto to : g[i])
			up[to.first][1] = up[i][1] + sum - to.second;
	}
	
	int ans = 1e9;
	
	for (int i = 1; i <= n; ++i) {
		if (g[i].size ()) {
			//cerr << i << " " << dp[i][1] + up[i][1] << "\n";
			ans = min (ans, dp[i][1] + up[i][1]);
		}
	}	
	
	cout << ans << ".00";
	
	return 0;
}