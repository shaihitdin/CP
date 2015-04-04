#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;
const long long mod = 10000007;
long long a[50][50], sum[50][50], ans;
long long n, m;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= n; ++i)
		sum[i][1] = a[i][1];
	a[1][m + 1] = 1;
	for (int j = 2; j <= m + 1; ++j)
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k <= n; ++k)
				sum[i][j] = (sum[i][j] + (sum[k][j - 1] * a[i][j]) ) % mod;
	if (sum[1][m + 1] >= 0)
		cout << sum[1][m + 1];
	else
		cout << mod + sum[1][m + 1];
	return 0;
}