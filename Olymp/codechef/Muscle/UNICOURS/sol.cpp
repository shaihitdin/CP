#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int ans = n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			ans = min (ans, n - a[i]);
		}
		cout << ans << "\n";
	}	
	return 0;
}