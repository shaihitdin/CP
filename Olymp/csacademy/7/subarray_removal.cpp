#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 2e5 + 100, oo = 1e18;

int a[N], sum[N];
int d[3][N][2];
int ans = -oo;
int sum2[N];
int mxs2[N], mxs[N];

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	for (int i = n; i; --i)
		sum2[i] = sum2[i + 1] + a[i];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < 2; ++k)
				d[i][j][k] = -oo;
	for (int i = 1, j = 0; i <= n; ++i) {
		mxs[i] = sum[i] - sum[j];
		if (sum[i] < sum[j])
			j = i;
	}
	for (int i = n, j = n + 1; i; --i) {
		mxs2[i] = sum2[i] - sum2[j];
		if (sum2[i] < sum2[j])
			j = i;
	}
	for (int i = 1; i < n; ++i)
		ans = max (ans, mxs[i]);
	for (int i = n; i > 1; --i)
		ans = max (ans, mxs2[i]);
	for (int i = 0; i <= n; ++i)
		d[0][i][0] = 0;
	for (int i = 1; i <= n; ++i) {
		d[0][i][1] = max (d[0][i - 1][1], 0ll) + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		d[1][i][1] = max (d[1][i - 1][1], d[0][i][1]);
		d[1][i][0] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		d[2][i][1] = d[2][i - 1][1] + a[i];
		d[2][i][1] = max (d[2][i][1], d[1][i - 1][0] + a[i]);
		d[2][i][1] = max (d[2][i][1], d[1][i - 1][1] + a[i]);
		ans = max (ans, d[2][i][1]);
	}
	cout << ans;
	return 0;
}