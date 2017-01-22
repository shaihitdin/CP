/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 510;

int col[N];
int anti[5];
bool g[N][N];
int n, m;

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = 1;
	}
	anti[0] = 2;
	anti[2] = 0;
	memset (col, -1, sizeof (col));
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j)
			cnt += g[i][j];
		if (cnt == n - 1)
			col[i] = 1;
	}
	for (int step = 1; step <= n + 10; ++step) {
		vector <int> c;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (g[i][j]) {
					if (col[i] != -1 && col[j] != -1) {
						if (abs (col[i] - col[j]) > 1) {
							cout << "No";
							return 0;
						}
					} else if (col[i] != -1 && col[i] != 1) {
						col[j] = col[i];
						goto here;
					} else if (col[j] != -1 && col[j] != 1) {
						col[i] = col[j];
	                	goto here;
					}
					continue;
				}
				if (col[i] == 1 || col[j] == 1) {
					cout << "No";
					return 0;
				}
				if (col[i] != -1 && col[j] != -1) {
					if (abs (col[i] - col[j]) < 2) {
						cout << "No";
						return 0;
					}
				} else if (col[i] != -1) {
					col[j] = anti[col[i]];
					goto here;
				} else if (col[j] != -1) {
					col[i] = anti[col[j]];
					goto here;
				} else {
					c.emplace_back (i);
				}
			}
		}
		for (int i : c) {
			if (col[i] == -1) {
				col[i] = 0;
				goto here;
			}
		}
		here:;
		c.clear ();
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; ++i) {
		if (col[i] == -1)
			col[i] = 1;
		cout << char ('a' + col[i]);
	}
	
	return 0;
}