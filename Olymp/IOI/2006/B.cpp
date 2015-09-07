#include <bits/stdc++.h>

using namespace std;

const int N = 1300, inf = 1e9;

int dp[N][N], pref1[N][N], pref[N][N], suff1[N][N], suff[N][N], f[N][N];
int n, m, a, b, c, d;
int k1, k2;

inline int get_sum (const int &sx, const int &sy, const int &fx, const int &fy) {
	return dp[fx][fy] - dp[sx - 1][fy] - dp[fx][sy - 1] + dp[sx - 1][sy - 1];
}

inline int get_min1 (const int &i, const int &l, const int &r) {
	//assert (r - l + 1 == k1);
	return min (suff1[i][l], pref1[i][r]);
}

inline int get_min (const int &sx, const int &sy, const int &fx, const int &fy) {
	//assert (fx - sx + 1 == k2 && fy - sy + 1 == k1);
	return min (suff[sx][sy], pref[fx][sy]);
}

inline bool inside (const int &px, const int &py, const int &sx, const int &sy, const int &fx, const int &fy) {
	return sx < px && px < fx && sy < py && py < fy;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d", &n, &m);

	scanf ("%d%d%d%d", &a, &b, &c, &d);
	
	swap (n, m);
	swap (a, b);
	swap (c, d);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &f[i][j]);

	k1 = b - d - 1, k2 = a - c - 1;
	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + f[i][j];
	
	for (int i = 1; i + c - 1 <= n; ++i) {
		pref1[i][0] = inf;
		for (int j = 1; j + d - 1 <= m; ++j)
			if (j % k1)
				pref1[i][j] = min (pref1[i][j - 1], get_sum (i, j, i + c - 1, j + d - 1));
			else
				pref1[i][j] = get_sum (i, j, i + c - 1, j + d - 1);
	    suff1[i][m - d + 2] = inf;
		for (int j = m - d + 1; j > 0; --j)
			if (j % k1)
				suff1[i][j] = min (suff1[i][j + 1], get_sum (i, j, i + c - 1, j + d - 1));
			else
				suff1[i][j] = get_sum (i, j, i + c - 1, j + d - 1);
	}
	
	
	for (int j = 1; j + k1 - 1 <= m; ++j) {
		pref[0][j] = inf;
		for (int i = 1; i <= n; ++i)
			if (i % k2)
				pref[i][j] = min (pref[i - 1][j], get_min1 (i, j, j + k1 - 1));
			else
				pref[i][j] = get_min1 (i, j, j + k1 - 1);
		suff[n + 1][j] = inf;
		for (int i = n; i; --i)
			if (i % k2)
				suff[i][j] = min (suff[i + 1][j], get_min1 (i, j, j + k1 - 1));
			else
				suff[i][j] = get_min1 (i, j, j + k1 - 1);
	}	
	
	int ans = -inf, ans1 = 1, ans2 = 1;
	
	for (int i = 1; i + a - 1 <= n; ++i) {
		for (int j = 1; j + b - 1 <= m; ++j) {
			int sx = i + 1, sy = j + 1, fx = sx + k2 - 1, fy = sy + k1 - 1;
			if (ans < get_sum (i, j, i + a - 1, j + b - 1) - get_min (sx, sy, fx, fy)) {
				ans = get_sum (i, j, i + a - 1, j + b - 1) - get_min (sx, sy, fx, fy);
				ans1 = i, ans2 = j;
			}
		}
	}
	
	int ans1_e = ans1 + a - 1, ans2_e = ans2 + b - 1;
	
	int ans3 = -1, ans4 = -1;
	
	for (int i = 1, i_e = i + c - 1; i_e <= n; ++i, ++i_e)
		for (int j = 1, j_e = j + d - 1; j_e <= m; ++j, ++j_e)
			if (inside (i, j, ans1, ans2, ans1_e, ans2_e) && inside (i_e, j_e, ans1, ans2, ans1_e, ans2_e)
			&& ans == get_sum (ans1, ans2, ans1_e, ans2_e) - get_sum (i, j, i_e, j_e))
				ans3 = i, ans4 = j;
	
	printf ("%d %d\n%d %d\n", ans2, ans1, ans4, ans3);
	
	return 0;
}