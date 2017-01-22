/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 100;

int nxt[N], a[N], pre[N];
vector <int> g[N];

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		g[a[i]].emplace_back (i);
	}	
	
	nxt[n] = n + 1;

	for (int i = n - 1; i >= 1; --i) {
		if (a[i] == a[i + 1])
			nxt[i] = nxt[i + 1];
		else
			nxt[i] = i + 1;
	}
	
	pre[1] = 0;

	for (int i = 2; i <= n; ++i)
		if (a[i] == a[i - 1])
			pre[i] = pre[i - 1];
		else
			pre[i] = i - 1;
	
	a[0] = 0, a[n + 1] = 0;
	
	int ans = -1, mn_val = 1e9;

	for (int i = 1; i <= k; ++i) {
		int res = 0;
		for (auto it : g[i]) {
			if (nxt[it] == it + 1) {
				if (nxt[it] == n + 1)
					continue;
				--res;
				res += (a[pre[it]] != a[nxt[it]]);
			}
			if (pre[it] == it - 1) {
				if (pre[it] == 0)
					continue;
				--res;
			}
		}
		cerr << res << "\n";
		if (res < mn_val)
			mn_val = res, ans = i;
	}
	
	cerr << "\n";
	
	cout << ans;
	
	return 0;
}