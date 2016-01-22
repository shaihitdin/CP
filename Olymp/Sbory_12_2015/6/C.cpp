#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char a[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	int sx, sy, fx, fy;

	sx = n + 1;
	sy = m + 1;
	fx = fy = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '*')
				sx = min (sx, i), fx = max (fx, i), sy = min (sy, j), fy = max (fy, j);
		}
	}	
	
	for (int i = sx; i <= fx; ++i) {
		for (int j = sy; j <= fy; ++j) {
			cout << a[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}