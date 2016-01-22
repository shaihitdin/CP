#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

char a[N];
int n;

int d[N][3][2]; // 0 - not used, 1 - now using, 2 - done using

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		a[i] -= '0';
	
	for (int i = 1; i <= n; ++i) {
		d[i][0][a[i]] = max (d[i][0][a[i]], d[i - 1][0][a[i] ^ 1] + 1);
		d[i][0][a[i] ^ 1] = max (d[i][0][a[i] ^ 1], d[i - 1][0][a[i] ^ 1]);
		
		d[i][1][a[i] ^ 1] = max (d[i][1][a[i] ^ 1], d[i - 1][1][a[i]] + 1);
		d[i][1][a[i] ^ 1] = max (d[i][1][a[i] ^ 1], d[i - 1][0][a[i]] + 1);
		d[i][1][a[i]] = max (d[i][1][a[i]], d[i - 1][1][a[i]]);
		d[i][1][a[i]] = max (d[i][1][a[i]], d[i - 1][0][a[i]]);

		d[i][2][a[i]] = max (d[i][2][a[i]], d[i - 1][1][a[i] ^ 1] + 1);
		d[i][2][a[i]] = max (d[i][2][a[i]], d[i - 1][2][a[i] ^ 1] + 1);
		d[i][2][a[i] ^ 1] = max (d[i][2][a[i] ^ 1], d[i - 1][1][a[i] ^ 1]);
		d[i][2][a[i] ^ 1] = max (d[i][2][a[i] ^ 1], d[i - 1][2][a[i] ^ 1]);
	}
	
	int ans = 0;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			ans = max (d[n][i][j], ans);
	
	cout << ans;
	
	return 0;
}