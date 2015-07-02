#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int d[N][N];
char a[N][N];
int n, m;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	int ans = 0;	
	
	for (int i = n; i; --i) {
		for (int j = m; j; --j) {
			if (a[i][j] == 'B') {
				if (d[i][j] != -1) {
					int now = -d[i][j] - 1;
					++ans;
					for (int k = 1; k <= i; ++k)
						for (int l = 1; l <= j; ++l)
							d[k][l] += now;
				}			
			} else if (a[i][j] == 'W') {
				if (d[i][j] != 1) {
					int now = -d[i][j] + 1;
					++ans;
					for (int k = 1; k <= i; ++k)
						for (int l = 1; l <= j; ++l)
							d[k][l] += now;			
				}
			}
		}
	}
	cout << ans;
	return 0;
}