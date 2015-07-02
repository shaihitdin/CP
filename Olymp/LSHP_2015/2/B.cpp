#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n, m, a[N][N];
int row[N], column[N];


inline int check () {
	
	memset (row, 0, sizeof (row));
	memset (column, 0, sizeof (column));	

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			column[j] += a[i][j];
			row[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
		if (row[i] < 0)
			return i;
	for (int j = 1; j <= m; ++j)
		if (column[j] < 0)
			return n + j;
	return 0;
}


int ans1[N * N * N];
char ans2[N * N * N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int cnt = 0; cnt <= 20000; ++cnt) {
		int result = check ();
		if (!check ()) {
			cout << cnt << "\n";
			for (int i = 0; i < cnt; ++i)
				cout << ans2[i] << " " << ans1[i] << "\n";
			return 0;
		}
		if (n < result) {
			ans1[cnt] = result - n;
			ans2[cnt] = 'C';
			for (int i = 1; i <= n; ++i)
				a[i][result - n] = -a[i][result - n];
		} else {
			ans1[cnt] = result;
			ans2[cnt] = 'R';
			for (int i = 1; i <= m; ++i)
				a[result][i] = -a[result][i];
		}
	}
	
	cout << -1;

	return 0;
}