#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	ll n, x, y;

	cin >> n >> x >> y;

	ll sum = 0;

	if (y < n) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			a[i] = y - n + 1;
		} else {
			a[i] = 1;
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