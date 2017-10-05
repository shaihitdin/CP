#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N], dp[N * 10];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort (a + 1, a + n + 1);
	n = unique (a + 1, a + n + 1) - a;
	
	int val = a[1];

	for (int i = 0; i < val; ++i)
		dp[i] = 1e9 + 7;

	for (int i = 1; i <= n; ++i)
		dp[a[i] % val] = min (dp[a[i] % val], a[i]);

 	for (int i = 1; i <= n; ++i) {
 		for (int now = a[i], step = 0; step < 5; step++, now += now) {
 			now %= val;
 			dp[now] = min (dp[now] * 1ll, (a[i] * 1ll * (1 << step)));
 			for (int j = 0, k = 0 + now; j < val; ++j, ++k) {
 				if (k >= val)
 					k -= val;
 				dp[k] = min (dp[k], dp[j] + dp[now]);
 			}
 		}
 	}
	int q;	
	cin >> q;

	while (q--) {
		int x;
		cin >> x;
		if (x == 0)
			cout << "YES\n";
		else if (x >= dp[x % val])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}