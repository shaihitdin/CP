#include <bits/stdc++.h>

using namespace std;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);

	int el = 0;
	
	ll ans = 0;
	
	for (int i = 1; i <= k; ++i) {
		++el;
		for (int j = i + k; j <= n; j += k) {
			ans += a[el + 1] - a[el];
		}
	}
	
	return 0;
}