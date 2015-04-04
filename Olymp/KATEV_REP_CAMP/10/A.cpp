#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

const int N = 301;

int n, m, q;
int x[N][3], y[N][3];

bool d[N][N][N];

pair <short, short> p[N][N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

inline bool inside (const int &pointx, const int &pointy, const int &lx, const int &ly, const int &rx, const int &ry) {
	return min (lx, rx) <= pointx && pointx <= max (lx, rx) && min (ly, ry) <= pointy && pointy <= max (ly, ry);
}



vector <pair <int, int> > ans;

int main () {

	freopen ("broadcast.in", "r", stdin);
	freopen ("broadcast.out", "w", stdout);

	scanf ("%d%d", &n, &m);

	scanf ("%d", &q);

	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d%d%d", &x[i][1], &y[i][1], &x[i][2], &y[i][2]);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!inside (i, j, x[1][1], y[1][1], x[1][2], y[1][2])) {
				d[1][i][j] = 1;
				p[1][i][j] = mkp (0, 0);
			}
	for (int it = 2; it <= q; ++it)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int k = 0; k < 4; ++k)
					if (!inside (i, j, x[it][1], y[it][1], x[it][2], y[it][2]) && d[it - 1][i + dx[k]][j + dy[k]]) {
						d[it][i][j] = 1;
						p[it][i][j] = mkp (i + dx[k], j + dy[k]);
					}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (d[q][i][j]) {
				int temp = q;
				ans.push_back (mkp (i, j));
				while (temp != 1) {
					ans.push_back (p[temp][i][j]);
					int oldx = i, oldy = j;
					i = p[temp][oldx][oldy].F;
					j = p[temp][oldx][oldy].S;
					--temp;
				}
				reverse (ans.begin(), ans.end());
				for (auto it : ans)
					printf ("%d %d\n", it.F, it.S);
				return 0;
			}
	puts ("Impossible");
	return 0;
}