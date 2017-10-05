#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int mn = a[1], mx = a[1];
	int ans1 = 0, ans2 = 0;
	for (int i = 2; i <= n; ++i) {
		if (mn > a[i]) {
			++ans1;
		}
		if (mx < a[i]) {
			++ans2;
		}
		mn = min (mn, a[i]);
		mx = max (mx, a[i]);
	}
	
	cout << ans2 << " " << ans1;
	
	return 0;
}