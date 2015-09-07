#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int a[N], n, d[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	d[0] = d[n + 1] = 0;
	
	for (int i = 1; i <= n; ++i)
		d[i] = n + 1;
	
	for (int i = 1; i <= n; ++i) {
		d[i] = min (d[i], a[i]);
		d[i] = min (d[i], d[i - 1] + 1);
	}

	for (int i = n; i >= 1; --i) {
		d[i] = min (d[i], d[i + 1] + 1);
	}
	
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		ans = max (ans, d[i]);
	}	
	cout << ans;
	
	return 0;
}