#include <bits/stdc++.h>

using namespace std;

const int N = 200;

char a[N][N];

int main () {

	freopen ("battle3.in", "r", stdin);
	freopen ("battle3.out", "w", stdout);
	
	int n, m, k;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	cin >> k;
		
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			++ans;
			for (int l = i; l <= i + k - 1; ++l) {
				if (a[l][j] != '.') {
					--ans;
					break;
				}
			}
			++ans;
			for (int l = j; l <= j + k - 1; ++l) {
				if (a[i][l] != '.') {
					--ans;
					break;
				}
			}
		}

	}
	
	cout << ans;
	
	return 0;
}