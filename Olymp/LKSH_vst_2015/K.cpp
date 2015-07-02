#include <bits/stdc++.h>

using namespace std;

int n, m, v[6], h[6], ans[6][6], a[6][6];

inline void rec (const int &i, const int &j) {
	
	if (i == n) {
		int sum = 0;
		for (int k = 1; k <= m; ++k) {
			if (abs (v[k]) != abs (a[n][k]))
				return;
			sum += -v[k];
		}
		if (!sum) {
			cout << "YES\n";
			for (int k1 = 1; k1 < n; ++k1) {
				for (int k2 = 1; k2 <= m; ++k2) {
					cout << ans[k1][k2] << " ";
				}
				cout << "\n";
			}
			for (int k = 1; k <= m; ++k)
				cout << -v[k] << " ";
			exit (0);
		}
		return;
	}
	
	if (j == m) {
		if (abs (h[i]) == abs (a[i][j]))
			ans[i][j] = -h[i], v[j] += -h[i];
		else
			return;
		rec (i + 1, 1);
		v[j] += h[i];
		return;
	}

	h[i] += a[i][j];
	v[j] += a[i][j];
	ans[i][j] = a[i][j];
	rec (i, j + 1);
	h[i] -= (2 * a[i][j]);
	v[j] -= (2 * a[i][j]);
	ans[i][j] = -a[i][j];
	rec (i, j + 1);
	h[i] += a[i][j];
	v[j] += a[i][j];

}

int main () {

	freopen ("rectangle-sum-0.in", "r", stdin);
	freopen ("rectangle-sum-0.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	rec (1, 1);

	cout << "NO";
	return 0;
}