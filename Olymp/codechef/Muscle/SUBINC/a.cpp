#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int a[N];
int t;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		memset (a, 0, sizeof (a));
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		++n;
		int lst = 1;
		long long ans = 0;
		
		for (int i = 1; i <= n; ++i) {
			if (a[i - 1] > a[i]) {
				long long diff = i - lst + 1;
				ans += (diff * (diff - 1)) / 2;
				lst = i;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}