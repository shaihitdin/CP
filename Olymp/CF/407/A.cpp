#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll a[N];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	ll now[2], mn[2];

	now[0] = now[1] = mn[0] = mn[1] = 0;
	ll ans = -1e18;
	for (int i = 1; i < n; ++i) {
		if (i & 1) {
			now[0] += abs (a[i] - a[i + 1]);
			now[1] -= abs (a[i] - a[i + 1]);
		} else {
			now[0] -= abs (a[i] - a[i + 1]);
			now[1] += abs (a[i] - a[i + 1]);		
		}
		ans = max (ans, now[0] - mn[0]);
		ans = max (ans, now[1] - mn[1]);
		mn[0] = min (mn[0], now[0]);
		mn[1] = min (mn[1], now[1]);
	}

	cout << ans;
	
	return 0;
}