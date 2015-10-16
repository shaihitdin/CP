#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100, oo = 1e9;

typedef long long ll;

ll a[N], pref_or[N], suff_or[N];
ll n, k, x;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k >> x;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		pref_or[i] = pref_or[i - 1] | a[i];
	}
	
	for (int i = n; i >= 1; --i) {
		suff_or[i] = suff_or[i + 1] | a[i];
	}
	
	ll ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j)
			a[i] *= x;
		ans = max (ans, a[i] | pref_or[i - 1] | suff_or[i + 1]);
	}
	
	cout << ans;
	
	return 0;
}