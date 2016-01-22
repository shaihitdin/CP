#include <bits/stdc++.h>

using namespace std;

const int N = 110, oo = 1e8;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int d[3][N][N];
char a[N][N];
int n, m;

inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

inline void dijkstra (int d[N][N], int vx, int vy, int flag) {
	set <pair <int, pair <int, int> > > Set;
	if (flag == 31) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				d[i][j] = oo;
				if (i == 1 || j == 1 || i == n || j == m) {
					if (a[i][j] == '*')
						continue;
					if (a[i][j] == '#')
						d[i][j] = 1;
					else
						d[i][j] = 0;
					Set.insert (make_pair (d[i][j], make_pair (i, j)));
				}
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				d[i][j] = oo;
			}
		}
		d[vx][vy] = 0;
		Set.insert (make_pair (0, make_pair (vx, vy)));
	}
	while (Set.size ()) {
		auto u = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (int i = 0; i < 4; ++i) {
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (inside (nx, ny) && a[nx][ny] != '*' && d[nx][ny] > d[u.first][u.second] + (a[nx][ny] == '#')) {
				Set.erase (make_pair (d[nx][ny], make_pair (nx, ny)));
				d[nx][ny] = d[u.first][u.second] + (a[nx][ny] == '#');
				Set.insert (make_pair (d[nx][ny], make_pair (nx, ny)));
			}
		}
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t_num;
	
	cin >> t_num;

	while (t_num--) {
		cin >> n >> m;
		int px[3], py[3], cns = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
				if (a[i][j] == '$')
					px[++cns] = i, py[cns] = j;
			}
		}
		dijkstra (d[0], 0, 0, 31);
		dijkstra (d[1], px[1], py[1], 0);
		dijkstra (d[2], px[2], py[2], 0);
		int ans = oo;
		ans = min (ans, d[0][px[1]][py[1]] + d[1][px[2]][py[2]]);
		ans = min (ans, d[0][px[2]][py[2]] + d[2][px[1]][py[1]]);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == '#')
					ans = min (ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
				else
					ans = min (ans, d[0][i][j] + d[1][i][j] + d[2][i][j]);
			}
		}
		cout << ans << "\n";
	}	
	
	return 0;
}