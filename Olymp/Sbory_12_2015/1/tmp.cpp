#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	ll n, x, y;

	cin >> n >> x >> y;

	ll need = y / n;
	ll rem = y % n;

	ll sum = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (i <= rem) {
			a[i] = need + 1;
		} else {
			a[i] = need;
		}
		sum += a[i] * 1ll * a[i];
	}

	if (sum < x) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << "\n";
	}
	
	return 0;
}