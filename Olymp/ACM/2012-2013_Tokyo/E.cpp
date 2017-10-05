#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

int dist[51][51][8][51][51];
char a[51][51];
int d[51][51][4];
int ddx[][2] = {{0, 1}, {0, 1}, {-1, -1}, {+2, +2}};
int ddy[][2] = {{2, 2}, {-1, -1}, {0, +1}, {0, +1}};
int n, m;
int st[51 * 51 * 51];
inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*';
}

inline void calc (int bx, int by, int sx, int sy, int dist[][51]) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dist[i][j] = 0;
	dist[bx][by] = dist[bx + 1][by + 1] = dist[bx][by + 1] = dist[bx + 1][by] = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '*') {
				dist[i][j] = -1;
			}
		}
	}
	if (!inside (sx, sy))
		return;
	dist[sx][sy] = 1;
	int stq = 0, enq = 0;
	st[++enq] = sx, st[++enq] = sy;
	while (stq < enq) {
		int x = st[++stq], y = st[++stq];
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (inside (nx, ny) && !dist[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1;
				st[++enq] = nx, st[++enq] = ny;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			--dist[i][j];
			dist[i][j] = max (dist[i][j], -1);
		}
	}
}

inline int mincost (int sx1, int sy1, int sx2, int sy2, int d1[][51], int d2[][51]) {
	if (!inside (sx1, sy1) || !inside (sx2, sy2))
		return 1e9;
	if (d1[sx1][sy1] == -1 || d1[sx2][sy2] == -1)
		return 1e9;
	return min (d1[sx1][sy1] + d2[sx2][sy2], d1[sx2][sy2] + d2[sx1][sy1]);
}


int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	while (1) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
			}
		}
		if (a[1][1] == 'X') {
			cout << 0 << "\n";
			continue;
		}		

		for (int i = 1; i + 1 <= n; ++i) {
			for (int j = 1; j + 1 <= m; ++j) {
					calc (i, j, i - 1, j, dist[i][j][0]);
					calc (i, j, i - 1, j + 1, dist[i][j][1]);
					calc (i, j, i, j - 1, dist[i][j][2]);
					calc (i, j, i + 1, j - 1, dist[i][j][3]);
					calc (i, j, i + 2, j, dist[i][j][4]);
					calc (i, j, i + 2, j + 1, dist[i][j][5]);
					calc (i, j, i, j + 2, dist[i][j][6]);
					calc (i, j, i + 1, j + 2, dist[i][j][7]);
			}
		}

		int xx = n + 1, yy = m + 1;
		vector <int> wowo;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == 'X')
					xx = min (xx, i), yy = min (yy, j);
				if (a[i][j] == '.')
					wowo.emplace_back (i), wowo.emplace_back (j);
			}
		}	    
		
		set <pair <int, pair <pair <int, int>, int> > > Set;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int side = 0; side < 4; ++side)
					d[i][j][side] = 1e9;

		
		
		for (int it = 1; it <= 4; ++it) {
			d[xx][yy][it - 1] = mincost (wowo[0], wowo[1], wowo[2], wowo[3], dist[xx][yy][it * 2 - 1], dist[xx][yy][it * 2 - 2]);
			Set.insert (make_pair (d[xx][yy][it - 1], make_pair (make_pair (xx, yy), it - 1)));
		}
		


		while (Set.size ()) {
			auto it = *Set.begin ();
			Set.erase (Set.begin ());
			int x = it.second.first.first;
			int y = it.second.first.second;
			int z = it.second.second;
			for (int i = 0; i < 4; ++i) {
				if (i == z) {
					for (int k1 = 0; k1 < 2; ++k1) {
						for (int k2 = 0; k2 < 2; ++k2) {
							if (inside (x + dx[i] + k1, y + dy[i] + k2) && a[x + dx[i] + k1][y + dy[i] + k2] == '*')
								goto end;
						}
					}
					if (d[x + dx[i]][y + dy[i]][i ^ 1] > d[x][y][i] + 1) {
						Set.erase (make_pair (d[x + dx[i]][y + dy[i]][i ^ 1], make_pair (make_pair (x + dx[i], y + dy[i]), i ^ 1)));
						d[x + dx[i]][y + dy[i]][i ^ 1] = d[x][y][i] + 1;
						Set.insert (make_pair (d[x + dx[i]][y + dy[i]][i ^ 1], make_pair (make_pair (x + dx[i], y + dy[i]), i ^ 1)));
					}
					end:;
					continue;
				}
				if (d[x][y][i] > d[x][y][z] + mincost (x + ddx[i][0], y + ddy[i][0], x + ddx[i][1], y + ddy[i][1], dist[x][y][z * 2], dist[x][y][z * 2 + 1])) {
					Set.erase (make_pair (d[x][y][i], make_pair (make_pair (x, y), i)));
					d[x][y][i] = d[x][y][z] + mincost (x + ddx[i][0], y + ddy[i][1], x + ddx[i][1], y + ddy[i][1], dist[x][y][z * 2], dist[x][y][z * 2 + 1]);
					Set.insert (make_pair (d[x][y][i], make_pair (make_pair (x, y), i)));
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < 4; ++i) 
			ans = min (ans, d[1][1][i]);
		cout << ans << "\n";
	}
	
	
	
	return 0;
}