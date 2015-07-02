#include <bits/stdc++.h>

using namespace std;

const int N = 600;

bool u[N][N];

char a[N][N];

inline void dfs (const int &x, const int &y) {
	if (u[x][y])
		return;
	u[x][y] = 1;
	for (int i = y - 1; i && a[x][i] == '.'; --i) {
		can
	}
}

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	cin >> sx >> sy;
	swap (sx, sy);
	cin >> fx >> fy;
	swap (fx, fy);
	dfs (sx, sy);
	return 0;
}