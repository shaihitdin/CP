/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100;

int a[N][N], b[N];

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int cnt = 0, mn = 10000, mnpos = -1;
			for (int k = 1; k <= n; ++k) {
				if (a[j][k] == 0)
					continue;
				if (mn > a[j][k]) {
					mn = a[j][k];
					cnt = 1;
				} else if (mn == a[j][k]) {
					++cnt;
				}
			}
			if (cnt == n - i) {
				b[j] = mn;
				for (int k = 1; k <= n; ++k)
					a[j][k] = 0, a[k][j] = 0;
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (b[i] == 0)
			b[i] = n;
		cout << b[i] << " ";
	}	

	return 0;
}