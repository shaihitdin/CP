#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 1, inf = 1e9 + 7;

vector <int> a[4], b[4];
int n, res = inf;

int d[4][N];

int ans[4][N];
int num[4];

bool u[4];

inline void check () {
	memset (d, 0, sizeof (d));
	memset (ans, 0, sizeof (ans));
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = d[i][j - 1] + b[i][j];
	for (int i = 1; i < n; ++i)
		ans[1][i] = d[2][i] + d[3][n] - d[3][i];
	ans[2][n - 1] = ans[1][n - 1];
	for (int i = n - 2; i; --i)
		ans[2][i] = min (ans[1][i], ans[2][i + 1]);
	for (int i = 1; i < n - 1; ++i)
		res = min (res, d[1][i] + ans[2][i + 1] - d[2][i]);
}

inline void rec (const int &lvl) {
	if (lvl == 4) {
		for (int i = 1; i <= 3; ++i)
			b[i] = a[num[i]];
		check();
		return;
	}
	
	for (int i = 1; i <= 3; ++i) {
		if (!u[i]) {
			u[i] = 1;
			num[lvl] = i;
			rec (lvl + 1);
			u[i] = 0;
		}
	}
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= 3; ++i) {
		a[i].resize (n + 1);
		for (int j = 1; j <= n; ++j) {
			scanf ("%d", &a[i][j]);
		}
	}

	rec (1);

	printf ("%d", res);
	
	return 0;
}   	