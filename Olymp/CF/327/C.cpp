#include <bits/stdc++.h>

using namespace std;

const int N = 1100, oo = 1e9;

char a[N][N];
int d[4][N][N];

pair <int, int> st[N * N * 2];
int n, m;
int stq, enq;

inline bool inside (const pair <int, int> &ss) {
	return 1 <= ss.first && ss.first <= n && 1 <= ss.second && ss.second <= m;
}

int dx[] = {-1, 0, 0, +1};
int dy[] = {0, -1, +1, 0};

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	memset (d, -1, sizeof (d));

	for (int k = 1; k <= 3; ++k) {
		stq = enq = N * N;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == k + '0')
					d[k][i][j] = 0, st[++enq] = make_pair (i, j);
		
		while (stq < enq) {
			auto v = st[++stq];
			for (int i = 0; i < 4; ++i) {
				auto nv = make_pair (v.first + dx[i], v.second + dy[i]);
				if (!inside (nv))
					continue;
				if (a[nv.first][nv.second] == '.' && d[k][nv.first][nv.second] == -1) {
					d[k][nv.first][nv.second] = d[k][v.first][v.second] + 1;
					st[++enq] = nv;
				} else if (a[nv.first][nv.second] != '#' && d[k][nv.first][nv.second] == -1) {
					d[k][nv.first][nv.second] = d[k][v.first][v.second];
					st[stq--] = nv;
				}
			}
		}
		/*
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cerr << d[k][i][j] << " ";
			}
			cerr << "\n";
		}
		
		cerr << "\n";
		*/
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (d[k][i][j] == -1)
					d[k][i][j] = oo;
	}
	
	int ans = oo;
	/*
	for (int k = 2; k <= 3; ++k) {
		int res = oo;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == k + '0')
					res = min (res, d[1][i][j]);
			}
		}
		if (res == oo)
			continue;
		int k2 = 2 + (!(k & 1));
		int res2 = oo;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == k2 + '0')
					res2 = min (res2, min (d[1][i][j], d[k][i][j]));
			}		
		}
		if (res2 == oo)
			continue;
		ans = min (ans, res + res2);
	}
	*/
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '.')
				ans = min (ans, min (d[1][i][j] + d[2][i][j], oo) + d[3][i][j] - 2);
			else
				ans = min (ans, min (d[1][i][j] + d[2][i][j], oo) + d[3][i][j]);
		}
	}
	
	if (ans > 1e7) {
		cout << -1;
	} else {
		cout << ans;
	}
	return 0;
}