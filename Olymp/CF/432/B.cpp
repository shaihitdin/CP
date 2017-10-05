#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 2e6 + 100;

int n, x, y, cnt[N];
int sum[N], cnts[N];

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> x >> y;
	int z = x / y;
	
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	
	for (int i = 1; i < N; ++i)
		sum[i] = sum[i - 1] + i * 1ll * cnt[i];
	for (int i = 1; i < N; ++i)
		cnts[i] = cnts[i - 1] + cnt[i];
	int ans = 1e18;
	for (int i = 2; i <= 1e6; ++i) {
		int res = 0;
		for (int j = i; j < N; j += i) {
			int step = min (i - 1, z);
			res += ((cnts[j - 1] - cnts[j - step - 1]) * 1ll * (j) - (sum[j - 1] - sum[j - step - 1])) * y;
			res += (cnts[j - step - 1] - cnts[j - i]) * x;
		}
		ans = min (ans, res);
	}
	
	cout << ans;
		
	return 0;
}