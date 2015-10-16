#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;

char a[N][N], ans[N][N];

bool u[N][N];

inline bool check (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}



int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	for (int dx = -n; dx <= n; ++dx) {
		for (int dy = -n; dy <= n; ++dy) {
			bool flag = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (a[i][j] == 'o' && check (i + dx, j + dy) && a[i + dx][j + dy] == '.') {
						flag = 1;
					}
				}
			}

			if (!flag) {
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						if (a[i][j] == 'o' && check (i + dx, j + dy) && a[i + dx][j + dy] == 'x') {
							u[i + dx][j + dy] = 1;
						}
					}
				}				
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 'x' && !u[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}

	memset (ans, '.', sizeof (ans));
	
	for (int dx = -n; dx <= n; ++dx) {
		for (int dy = -n; dy <= n; ++dy) {
			bool flag = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (a[i][j] == 'o' && check (i + dx, j + dy) && a[i + dx][j + dy] == '.') {
						flag = 1;
					}
				}
			}

			if (!flag) {
				ans[n + dx][n + dy] = 'x';
			}
		}
	}
	
	
	cout << "YES\n";

	ans[n][n] = 'o';
	
	for (int i = 1; i <= 2 * n - 1; ++i) {
		for (int j = 1; j <= 2 * n - 1; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}