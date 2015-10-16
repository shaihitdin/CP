#include <bits/stdc++.h>

using namespace std;


const int N = 1e6 + 100;

int cnt[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		int d, n;
		cin >> d >> n;
		memset (cnt, 0, sizeof (cnt));
		int now = 0;
		long long ans = 0;
		cnt[now] = 1;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			now += x;
			now %= d;
			ans += cnt[now];
			++cnt[now];
		}
		cout << ans << "\n";
	}	

	return 0;
}