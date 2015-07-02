#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

inline int get_sum (const int &sx, const int &sy, const int &fx, const int &fy) {
	return d[fx][fy] - d[sx - 1][fy] - d[fx][sy - 1] + d[sx - 1][sy - 1];
}

int 

int main () {
	#define LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m >> a >> b >> c >> d;
	
	swap (n, m);
	swap (a, b);
	swap (c, d);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
	
	int ans = 0, ans_sx_b, ans_sy_b, ans_sx_s, ans_sy_s;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j % b) {
				if (pref_j[i][j - 1] < get_sum (i, j, i + a - 1, j + b - 1)) {
					pref_j[i][j] = get_sum (i, j, i + a - 1, j + b - 1);
					pref_pos_j[i][j] = j;
				} else {
					pref_j[i][j] = pref[i][j - 1];
					pref_pos_j[i][j] = pref_pos[i][j - 1];
				}
			} else {
				pref_j[i][j] = get_sum (i, j, i + a - 1, j + b - 1);
				pref_pos_j[i][j] = j;
			}
		}
		for (int j = m; j; --j) {
			if (j % b) {
				if (suff_j[i][j - 1] < get_sum (i, j, i + a - 1, j + b - 1)) {
					suff_j[i][j] = get_sum (i, j, i + a - 1, j + b - 1);
					suff_pos_j[i][j] = j;
				} else {
					suff_j[i][j] = suff_j[i][j - 1];
					suff_pos_j[i][j] = suff_pos_j[i][j - 1];
				}
			} else {
				suff_j[i][j] = get_sum (i, j, i + a - 1, j + b - 1);
				suff_pos_j[i][j] = j;
			}
		}
	}
	
	for (int i 
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (ans < )
		}
	}
	
	return 0;
}