#include <bits/stdc++.h>

using namespace std;

const int N = 3001;

int dp[N][N][2][2];
int a[3][N];

inline int rec (int l, int r, int f1, int f2) {
	if (dp[l][r][f1][f2] != -1)
		return dp[l][r][f1][f2];
	if (l > r)
		return 0;
	if (l == r) {
		return a[f1 + f2][l];
	}
	int x = 0;
	x = max (x, rec (l + 1, r, 0, f2) + a[f1 + 1][l]);
	x = max (x, rec (l + 1, r, 1, f2) + a[f1][l]);
/*
	x = max (x, rec (l, r - 1, f1, 0) + a[f2 + 1][r]);
	x = max (x, rec (l, r - 1, f1, 1) + a[f2][r]);
*/
	return dp[l][r][f1][f2] = x;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	
	int n;

	cin >> n;

	for (int i = 0; i <= 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	memset (dp, -1, sizeof (dp));
	
	cout << rec (1, n, 0, 0);
	
	
	return 0;
}