#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int a[N];
int n, d[N][N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cin >> n;
/*
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
*/	
	
	for (int n = 1; n <= 33; ++n) {
		if ((n - 1) % 4 != 3)
			continue;
		cout << n - 1 << ": ";
		memset (d, 0, sizeof (d));
		for (int i = 1; i <= n; ++i) {
			d[1][i][i] = 1;
		}
		
		for (int i = 2, sign = 1; i <= n; ++i) {
			for (int j = 1; j <= n + 1 - i; ++j, sign *= -1) {
				for (int k = 1; k <= n; ++k) {
					d[i][j][k] = d[i - 1][j][k] + (d[i - 1][j + 1][k] * sign);
		    	}
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			cout << d[n][1][i] << " ";
		}
		cout << '\n';		
	}
	return 0;
}