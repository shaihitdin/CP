#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 260;

ll dp[2][N][N];

int n, k;
ll sum[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> k;

	dp[0][n][n] = 1; // 1st - Stage, 2nd - cnt, 3rd - NOW

	for (int i = 1; i <= k; ++i) {
		int v = i & 1;
		int op = v ^ 1;
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k)
				dp[v][j][k] = 0;
		
		for (int j = 1; j <= n; ++j) {
			sum[n] = dp[op][j][n];
			for (int kk = n - 1; kk >= 0; --kk)
				sum[kk] = sum[kk + 1] + dp[op][j][kk];
			for (int kk = 0; kk <= j; ++kk) {
				dp[v][j - kk][kk] += sum[kk];
			}
		}
	}

	int v = k & 1;
	ll ans = 0;
	
	for (int i = 0; i <= n; ++i)
		ans += dp[v][0][i];
	
	cout << ans;
	
	return 0;
}