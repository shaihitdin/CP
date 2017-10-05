#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100, oo = 1e9 + 10;

int ans[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, x;
	cin >> n >> x;

	vector <pair <int, int> > ls[N], rs[N];
	
	for (int i = 1; i <= n; ++i) {
		int l, r, x;
		cin >> l >> r >> x;
		ls[l].emplace_back (make_pair (r - l + 1, x));
		rs[r].emplace_back (make_pair (r - l + 1, x));
	}
	
	int res = oo + oo;
	
	for (int i = 1; i < N; ++i)
		ans[i] = oo;
	
	for (int i = 1; i < N; ++i) {
		for (auto it : rs[i - 1]) {
			ans[it.first] = min (ans[it.first], it.second);
		}		
		for (auto it : ls[i])
			if (x >= it.first && ans[x - it.first] != oo)
				res = min (res, ans[x - it.first] + it.second);
	}

	if (res == oo * 2) {
		cout << -1;
		return 0;
	}
	
	cout << res;
	
	return 0;
}