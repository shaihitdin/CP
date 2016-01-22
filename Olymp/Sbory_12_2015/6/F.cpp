#include <bits/stdc++.h>

using namespace std;

const int N = 11;

bool u[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char a[N][N];
int n, m;

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*';
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	
	cin >> n >> m;

	memset (u, 1, sizeof (u));
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	int sx, sy, direction;
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 'U')
				sx = i, sy = j, direction = 0;
			else if (a[i][j] == 'R')
				sx = i, sy = j, direction = 1;
			else if (a[i][j] == 'D')
				sx = i, sy = j, direction = 2;
			else if (a[i][j] == 'L')
				sx = i, sy = j, direction = 3;
		}
	}	
	
	for (int cnt = 0; cnt < 10000; ++cnt) {
		ans += u[sx][sy];
		u[sx][sy] = 0;
		if (inside (sx + dx[direction], sy + dy[direction]))
			sx += dx[direction], sy += dy[direction];
		else
			direction = (direction + 1) % 4;
	}
	
	cout << ans;
	
	return 0;
}