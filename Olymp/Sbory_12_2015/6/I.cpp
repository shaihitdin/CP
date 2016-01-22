#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

typedef long long ll;

int n, m, k;

ll a[N], times1[N], times2[N], l[N], r[N], d[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= m; ++i)
		cin >> l[i] >> r[i] >> d[i];
	
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		++times2[x];
		--times2[y + 1];
	}
	
	ll now = 0;
	for (int i = 1; i <= m; ++i) {
		now += times2[i];
		times1[l[i]] += now * d[i];
		times1[r[i] + 1] -= now * d[i];
	}
	
	now = 0;

	for (int i = 1; i <= n; ++i) {
		now += times1[i];
		cout << a[i] + now << " ";
	}
	
	return 0;
}