#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char a[N][N];
int cnt[N][N];

int dx[] = {+1, 0, -1, 0};
int dy[] = {0, +1, 0, -1};
int n, m;


inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '@';
}



int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;
	getchar ();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = getchar ();
		}
		getchar ();
	}
	
	int psx = 2;
	int psy = 2;
	int ans = 0;
	int dir = 0;
	for (int step = 1; step <= 5e6; step++) {
		++cnt[psx][psy];
		if (psx == n - 1 && psy == m - 1) {
			cout << ans;
			return 0;
		}
		if (inside (psx + dx[dir], psy + dy[dir])) {
			int flag = 1;
			for (int i = 0; i < 4; ++i) {
				int nx = psx + dx[i], ny = psy + dy[i];
				int cx = psx + dx[dir], cy = psy + dy[dir];
				if (!inside (nx, ny))
					continue;
			   	if (cnt[cx][cy] > cnt[nx][ny]) {
			   		flag = 0;
			   	}
			}
			if (flag) {
				goto here;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int nx = psx + dx[i], ny = psy + dy[i];
			int cx = psx + dx[dir], cy = psy + dy[dir];
			if (!inside (nx, ny))
				continue;
		   	if ((!inside (cx, cy)) || (inside (nx, ny) && cnt[nx][ny] < cnt[cx][cy])) {
		   		dir = i;
		   	}
		}
		here:;
		++ans;
		psx += dx[dir];
		psy += dy[dir];
	}	
	
	cout << -1;

	return 0;
}