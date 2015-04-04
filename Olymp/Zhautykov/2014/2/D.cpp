#include <iostream>
#include <assert.h>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1000001;
// 1 = West
// 2 = North
// 3 = East
// 4 = South
int n, m, r, k, p;
vector <int> a[N];
vector <long long> d[N];
int mp[11][N];
char q[N];
int x[N], y[N], temp, posx, posy;
bool flag;
long long ans;
inline bool inside (const int &x, const int &y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}
int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};
inline pair <int, int> lazy (const int &x, const int &y, const int &direction) {
	if (
}
inline int cou (const int &x, const int &y, const int &left, const int &direction, const int &h) {
	if (a[x][y] == 0) {}	
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> n >> m >> r >> k >> p;
	for (int i = 0; i <= n + 1; ++i) {
		a[i].resize(m + 1);
		d[i].resize(m + 1);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for (int i = 1; i <= k; ++i) {	
		cin >> q[i] >> x[i] >> y[i];
		if (y[i] != 1)
			flag = 1;
	}
	if (flag) {
		for (int i = 1; i <= k; ++i) {
			int id = -1;
			temp = r;
			if (q[i] == 'W') {
				posx = x[i];
				posy = 1;
				id = 0;
			}
			if (q[i] == 'N') {
				posx = 1;
				posy = x[i];
				id = 1;
			}
			if (q[i] == 'E') {
				posx = x[i];
				posy = m;
				id = 2;			
			}
			if (q[i] == 'S') {
				posx = n;
				posy = x[i];
				id = 3;			
			}
			while (inside (posx, posy) && temp != 0) {
				if (a[posx][posy] >= y[i]) {
					--temp;
					--a[posx][posy];
				}
				posx += dx[id];
				posy += dy[id];
			}
		}
	}

	else {
		for (int i = 1; i <= k; ++i) {
				temp = r;
			
		}	
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
	for (int i = p; i <= n; ++i)
		for (int j = p; j <= m; ++j)
			ans = max (ans, d[i][j] - d[i - p][j] - d[i][j - p] + d[i - p][j - p]);
	cout << ans;
	return 0;
}