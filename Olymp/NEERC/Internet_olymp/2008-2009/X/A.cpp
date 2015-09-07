#include <bits/stdc++.h>

using namespace std;

char a[200][200];

int main () {

	freopen ("battle3.in", "r", stdin);
	freopen ("battle3.out", "w", stdout);

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	int k;

	cin >> k;

	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			bool flag = 1;
			for (int ll = 0; ll < k; ++ll) {
				if (a[i][j - ll] != '.')
					flag = 0;
			}
			ans += flag;
			flag = 1;
			for (int ll = 0; ll < k; ++ll) {
				if (a[i - ll][j] != '.')
					flag = 0;
			}
			ans += flag;
		}
	}
	
	cout << ans;
	
	return 0;
}