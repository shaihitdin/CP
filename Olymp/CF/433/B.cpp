#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 100;

#define int ll

struct node {
	int x, cost;
};

int a[N];
int mncost[N];
int e[N], st[N];
int n, m, k;
vector <node> gout[N], gin[N];

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++i) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		if (f == 0) {
			gout[d].push_back ({t, c});
		} else {
			gin[d].push_back ({f, c});
		}
	}
	
	int now = 0, res = 0;
	
	for (int i = 1; i <= n; ++i)
		mncost[i] = 1e9;

	for (int start = 1; start <= 1e6; ++start) {
		if (now == n)
			st[start] = res;
		else
			st[start] = 1e18;
		
		if (start - 1 >= 1)
			st[start] = min (st[start], st[start - 1]);

		for (auto it : gin[start]) {
			if (mncost[it.x] > it.cost) {
				if (mncost[it.x] == 1e9)
					++now;
				else
					res -= mncost[it.x];
				res += it.cost;
				mncost[it.x] = it.cost;
			}
		}
	}
	
	
	now = 0, res = 0;

	for (int i = 1; i <= n; ++i)
		mncost[i] = 1e9;

	for (int end = N - 1; end >= 1; --end) {
		if (now == n)
			e[end] = res;
		else
			e[end] = 1e18;

		if (end + 1 < N)
			e[end] = min (e[end], e[end + 1]);
		for (auto it : gout[end]) {
			if (mncost[it.x] > it.cost) {
				if (mncost[it.x] == 1e9)
					++now;
				else
					res -= mncost[it.x];
				res += it.cost;
				mncost[it.x] = it.cost;
			}
		}
	}
	
	int ans = 1e18;
	
	for (int it = 1; it + k - 1 < N; ++it) {
		ans = min (ans, st[it] + e[it + k - 1]);
	}
	
	if (ans == 1e18) {
		cout << -1;
		return 0;
	}	
	cout << ans;
	return 0;
}