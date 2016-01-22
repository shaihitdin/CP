#include <bits/stdc++.h>

using namespace std;

const int N = 600, oo = 1e9 + 100;

int sum[2][N][N], d[N][N];
int dx[] = {-1, +1, -2, -2, -1, +1, +2, +2};
int dy[] = {-2, -2, -1, +1, +2, +2, -1, +1};
pair <int, int> st[N * N];
int stq, enq;
int n;

inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main () {

	freopen ("knights.in", "r", stdin);
	freopen ("knights.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int k;
	
	cin >> n >> k;

	while (k--) {
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = oo;
		d[x][y] = 0;
		stq = enq = 0;
		st[enq++] = make_pair (x, y);

		while (stq < enq) {
			auto p = st[stq++];
			for (int i = 0; i < 8; ++i) {
				auto np = make_pair (p.first + dx[i], p.second + dy[i]);
				if (!inside (np.first, np.second))
					continue;
				if (d[np.first][np.second] == oo) {
					d[np.first][np.second] = d[p.first][p.second] + 1;
					st[enq++] = np;
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] == oo) {
					sum[0][i][j] = oo;
					sum[1][i][j] = oo;
					continue;
				}
				sum[d[i][j] & 1][i][j] = max (sum[d[i][j] & 1][i][j], d[i][j]);
				sum[(d[i][j] & 1) ^ 1][i][j] = oo;
			}
		}	
	}

	
	int ans = oo;

	int x = -1, y = -1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans = min (ans, min (sum[0][i][j], sum[1][i][j]));
		}
	}

	if (ans == oo) {
		cout << -1;
	} else {
		cout << ans;
	}
	
	return 0;
}