#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char a[N][N];
int cnt;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool u[N][N];
int banned_i, banned_j;

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

inline void dfs (int x, int y) {
	if (u[x][y] || (banned_i == x && banned_j == y))
		return;
	u[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (inside (nx, ny) && a[nx][ny] == '#')
			dfs (nx, ny);
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				++cnt;
			}
		}
	}

	int ans = min (2, cnt - 1);

	if (cnt <= 2) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int tmp = 0;
			if (a[i][j] != '#')
				continue;
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (inside (nx, ny) && a[nx][ny] == '#')
					++tmp;
			}
			ans = min (ans, tmp);
		}
	}
	
	
	for (banned_i = 1; banned_i <= n; ++banned_i) {
		for (banned_j = 1; banned_j <= m; ++banned_j) {
			if (a[banned_i][banned_j] == '.')
				continue;
			memset (u, 0, sizeof (u));
			int ds = 0;
			for (int k = 1; k <= n; ++k) {
				for (int kk = 1; kk <= m; ++kk) {
					if (k == banned_i && kk == banned_j)
						continue;
					if (a[k][kk] == '#' && !u[k][kk]) {
						dfs (k, kk);
						++ds;
					}
				}
			}
			if (ds > 1) {
				cout << 1;
				return 0;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}