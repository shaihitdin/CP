#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int dx[] = {-2, -2, +2, +2}, dy[] = {-2, +2, +2, -2};
int dx2[] = {-1, -1, +1, +1}, dy2[] = {-1, +1, +1, -1};


inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= 10 && 1 <= y && y <= 10;
}


bool u[N][N];
int ans = 0;
string s[N];

inline void dfs (const int &x, const int &y, const int &px, const int &py, const int &tmp) {
	ans = max (ans, tmp);
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!inside (nx, ny))
			continue;
		int nx2 = x + dx2[i], ny2 = y + dy2[i];
		if (s[nx2][ny2] == 'B' && !u[nx2][ny2] && ((s[nx][ny] != 'W' && s[nx][ny] != 'B') || (nx == px && ny == py))) {
			u[nx2][ny2] = 1;
			dfs (nx, ny, px, py, tmp + 1);
			u[nx2][ny2] = 0;
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		for (int i = 1; i <= 10; ++i) {
			cin >> s[i];
			s[i] = ' ' + s[i];
		}
	
		ans = 0;
		memset (u, 0, sizeof (u));

		for (int i = 1; i <= 10; ++i) {
			for (int j = 1; j <= 10; ++j) {
				if (s[i][j] == 'W')
					dfs (i, j, i, j, 0);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}