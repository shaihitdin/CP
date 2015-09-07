#include <bits/stdc++.h>

using namespace std;

const int N = 200;

bool u[N][N];
int n, m;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= n; ++i)
			u[x][i] = 1, u[i][y] = 1;
		for (int i = x, j = y; i >= 1 && j >= 1; --i, --j)
			u[i][j] = 1;
		for (int i = x, j = y; i <= n && j <= n; ++i, ++j)
			u[i][j] = 1;
		for (int i = x, j = y; i >= 1 && j <= n; --i, ++j)
			u[i][j] = 1;
		for (int i = x, j = y; i <= n && j >= 1; ++i, --j)
			u[i][j] = 1;
	}
	
	int ans = 0;	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ans += !u[i][j];
	
	cout << ans;
	
	return 0;
}