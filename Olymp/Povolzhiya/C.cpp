#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int n, m, d[N][N];
char a[N][N];

inline bool calc (const int &x) {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			d[i][j] = 1e5;

	d[1][1] = a[1][1] != '.';
	if (d[1][1] > x)
		d[1][1] = 1e5;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (d[i - 1][j] != 1e5) {
				if (a[i][j] == '.') {
					d[i][j] = 0;
				} else if (a[i][j] == a[i - 1][j]) {
					if (d[i - 1][j] + 1 <= x)
						d[i][j] = min (d[i][j], d[i - 1][j] + 1);
				} else if (1 <= x) {
					d[i][j] = min (d[i][j], 1);
				}
			}
			if (d[i][j - 1] != 1e5) {
				if (a[i][j] == '.') {
					d[i][j] = 0;
				} else if (a[i][j] == a[i][j - 1]) {
					if (d[i][j - 1] + 1 <= x)
						d[i][j] = min (d[i][j], d[i][j - 1] + 1);
				} else if (1 <= x) {
					d[i][j] = min (d[i][j], 1);
				}
			}
		}
	}
	
	return d[n][m] != 1e5;
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	
	int l = -1, r = n - 1 + m - 1 + 1;
	
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (calc (mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	
	
	calc (r);

	cout << r << "\n";
	
	int i = n, j = m;

	vector <pair <int, int> > ans;
	
	while (i != 1 || j != 1) {
		ans.emplace_back (make_pair (i, j));
		if (d[i - 1][j] != 1e5) {
			if (a[i][j] == '.') {
				--i;
				continue;
			} else if (a[i][j] == a[i - 1][j]) {
				if (d[i - 1][j] + 1 <= r) {
					if (d[i - 1][j] + 1 == d[i][j]) {
						--i;
						continue;
					}
				}
			} else if (1 <= r) {
				--i;
				continue;
			}
		}
		if (d[i][j - 1] != 1e5) {
			if (a[i][j] == '.') {
				--j;
				continue;
			} else if (a[i][j] == a[i][j - 1]) {
				if (d[i][j - 1] + 1 <= r) {
					if (d[i][j - 1] + 1 == d[i][j]) {
						--j;
						continue;
					}
				}
			} else if (1 <= r) {
				--j;
				continue;
			}
		}
	}	
	
	ans.emplace_back (make_pair (1, 1));
	
	reverse (ans.begin (), ans.end ());

	for (auto it : ans) {
		cout << it.first << " " << it.second << "\n";
	}
	
	return 0;
}