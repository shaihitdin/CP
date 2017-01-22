#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int a[N];

int main () {
	#ifdef Geodsso
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort (a + 1, a + n + 1);
		int ans = 0;
		for (int i = 1; i <= n / 2; ++i)
			ans += (a[n - i + 1] - a[i]);
		cout << ans << "\n";
	}

	return 0;
}