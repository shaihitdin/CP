#include <bits/stdc++.h>

using namespace std;

int pre[50][30];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int a[50], b[50], n, m;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];
	
	for (int i = 0; i <= n + n; ++i)
		for (int j = 0; j <= n; ++j)
			pre[i][j] = 201;
	
	for (int i = 0; i < (1 << n); ++i) {
		int balance = 0, mn_balance = 0, sum = 0;
		for (int j = 0; j < n; ++j) {
			if (bit (i, j)) {
				sum += a[j];
				++balance;
			} else {
				sum += b[j];
				--balance;
			}
			mn_balance = min (mn_balance, balance);
		}
		mn_balance = -mn_balance;
		for (int i = mn_balance; i <= n; ++i)
			pre[balance + n][i] = min (pre[balance + n][i], sum);
	}
	
	int ans = pre[n][0] * m;
	
	for (int balance = 1; balance <= n; ++balance) {
		int sum = pre[n + balance][0];
		for (int pl_end = 1; pl_end < m; ++pl_end) {
			if ((balance * pl_end) % (m - pl_end) == 0 && ((balance * pl_end) / (m - pl_end)) <= n) {
				int ch = (balance * pl_end) / (m - pl_end);
				int cnt = m - pl_end;
				int now = 0;
				int sum2 = 0;
				while (1) {
					if (now >= n)
						break;
					now += ch;
					sum2 += pre[n - ch][now];
					--cnt;
				}
				sum2 += pre[n - ch][n] * cnt;
				ans = min (ans, sum + sum2);
			}
			
			sum += pre[n + balance][min (n, balance * pl_end)];
		}
	}
	
	cout << ans;
	
	return 0;
}