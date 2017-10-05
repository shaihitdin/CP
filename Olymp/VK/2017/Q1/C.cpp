#include <bits/stdc++.h>

using namespace std;

#define fe first
#define se second
#define mp make_pair
#define eb emplace_back

const int N = 1050;

int n, m, k;
string s = "DLRU";
int dx[] = {+1, 0, 0, -1};
int dy[] = {0, -1, +1, 0};
int stq, enq;
int st[N * N * 3];
char a[N][N];
int d[N][N];
string ans;

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*';
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	cin >> n >> m >> k;
	
	if (k % 2 == 1) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	int sx = 0, sy = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'X')
				sx = i, sy = j;
	
	memset (d, -1, sizeof (d));
	d[sx][sy] = 0;
	st[enq++] = sx;
	st[enq++] = sy;
	while (stq != enq) {
		int x = st[stq++];
		int y = st[stq++];
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (inside (nx, ny) && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				st[enq++] = nx;
				st[enq++] = ny;
			}
		}
	}

	int x = sx, y = sy;

	for (int step = 1; step <= k; ++step) {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (inside (nx, ny) && step + d[nx][ny] <= k) {
				x = nx;
				y = ny;
				if (i == 0)
					ans += 'D';
				if (i == 1)
					ans += 'L';
				if (i == 2)
					ans += 'R';
				if (i == 3)
					ans += 'U';
				break;
			}
		}
		if (ans.size () == 0) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	
	cout << ans;
	
	return 0;
}