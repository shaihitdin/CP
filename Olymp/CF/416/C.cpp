#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5050;

int a[N];
int n, dp[N], mx[N], mn[N], sum[N];
bool used[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 0; i <= 5000; ++i) {
		mn[i] = n + 1;
		mx[i] = 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mn[a[i]] = min (mn[a[i]], i);
		mx[a[i]] = max (mx[a[i]], i);
	}
	
	dp[1] = 0;

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] ^ a[i];
	
	for (int i = 1; i <= n; ++i) {
		dp[i] = max (dp[i], dp[i - 1]);		
		memset (used, 0, sizeof (used));
		int sum = 0;
		for (int j = i, ok = 1; j <= n + 1 && ok;) {
			int till = j;
			while (j <= till) {
				if (!used[a[j]])
					sum ^= a[j];
				used[a[j]] = 1;
				till = max (till, mx[a[j]]);
				if (mn[a[j]] < i)
					ok = 0;								
				++j;
			}
			if (!ok)
				break;
			dp[j] = max (dp[j], dp[i] + sum);
		}
	}

	cout << max (dp[n + 1], dp[n]);
	
	return 0;
}