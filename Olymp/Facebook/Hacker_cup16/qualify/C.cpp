#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll sum[N], a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int t;
	
	cin >> t;

	for (int test_num = 1; test_num <= t; ++test_num) {
		int n, p;
		cin >> n >> p;
		cout << "Case #" << test_num << ": ";
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + a[i];
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			int l = -1, r = i;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (sum[i] - sum[mid] <= p)
					r = mid;
				else
					l = mid;
			}
			ans += i - r;
		}
		cout << ans << "\n";
	}


	return 0;
}