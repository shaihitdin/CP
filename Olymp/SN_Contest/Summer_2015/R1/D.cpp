#include <bits/stdc++.h>

using namespace std;

const int N = 410;

int d[30][N][N];
char a[N][N];
bool u[30];

inline int get_cnt (const int &sx, const int &sy, const int &fx, const int &fy, const int &color) {
	return d[color][fx][fy] - d[color][sx - 1][fy] - d[color][fx][sy - 1] + d[color][sx - 1][sy - 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int k, n, m;

	cin >> k;

	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int z = 0; z <= 25; ++z)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				d[z][i][j] = d[z][i - 1][j] + d[z][i][j - 1] - d[z][i - 1][j - 1] + (a[i][j] == (z + 'a'));
	
	int k2 = (k * (k + 1)) / 2;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int j1 = j; j1 >= 1; --j1) {
				if (k2 % (j - j1 + 1) != 0)
					continue;
				int i1 = i - (k2 / (j - j1 + 1)) + 1;
				if (i1 < 1)
					continue;
				assert (k2 == (i - i1 + 1) * (j - j1 + 1));
				bool flag = 0;
				int total = 0;
				memset (u, 0, sizeof (u));
				for (int z = 0; z <= 25; ++z) {
					int tmp = get_cnt (i1, j1, i, j, z);
					if (tmp == 0) {
						continue;
					}
					if (tmp > k || u[tmp]) {
						flag = 1;
						break;
					}
					++total;
					u[tmp] = 1;
				}
				if (total > k || flag)
					continue;
				if (total == k) {
					cout << i1 << " " << j1 << "\n" << i << " " << j;
					return 0;
				}
			}
		}
	}

	for (int i1 = 1; i1 <= n; ++i1) {
		for (int j1 = 1; j1 <= m; ++j1) {
			for (int j = j1; j <= m; ++j) {
				if (k2 % (j - j1 + 1) != 0)
					continue;
				int i = i + (k2 / (j - j1 + 1)) - 1;
				if (i > n)
					continue;
				assert (k2 == (i - i1 + 1) * (j - j1 + 1));
				bool flag = 0;
				int total = 0;
				memset (u, 0, sizeof (u));
				for (int z = 0; z <= 25; ++z) {
					int tmp = get_cnt (i1, j1, i, j, z);
					if (tmp == 0) {
						continue;
					}
					if (tmp > k || u[tmp]) {
						flag = 1;
						break;
					}
					++total;
					u[tmp] = 1;
				}
				if (total > k || flag)
					continue;
				if (total == k) {
					cout << i1 << " " << j1 << "\n" << i << " " << j;
					return 0;
				}
			}
		}
	}	
	
	return 0;
}