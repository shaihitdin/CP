#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9, N = 600;

int dx[] = {-1, 0};
int dy[] = {0, -1};

int n, m;

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

char a[N][N];
int d[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#')
				continue;
			for (int k = 0; k < 2; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (inside (nx, ny) && a[nx][ny] != '#')
					++d[i][j];
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		}
	}
	
	int q;

	cin >> q;

	while (q--) {
		int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;
		int ans = d[fx][fy] - d[sx - 1][fy] - d[fx][sy - 1] + d[sx - 1][sy - 1];
		for (int i = sx; i <= fx; ++i) {
			if (inside (i, sy - 1) && a[i][sy] != '#' && a[i][sy - 1] != '#')
				--ans;
		}
		for (int i = sy; i <= fy; ++i) {
			if (inside (sx - 1, i) && a[sx][i] != '#' && a[sx - 1][i] != '#')
				--ans;
		}
		cout << ans << "\n";
	}

	return 0;
}