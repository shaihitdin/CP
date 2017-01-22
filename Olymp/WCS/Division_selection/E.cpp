#include <bits/stdc++.h>

using namespace std;

int n;
int dp[18][230][1600];
vector <int> g[18][18][230];
int ans[18][18][230];
int ansq[1100];

const int bpr = 1e9 + 7;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline bool inside (int x) {
	return 0 <= x && x < n;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	freopen ("err", "w", stderr);
	#endif	
	
	int t;

	cin >> t;

	for (int test_num = 1; test_num <= t; ++test_num) {
		int n, m, cnt;
		cin >> n >> m >> cnt;
		g[n][m][cnt].emplace_back (test_num);
	}
	
	for (int m = 2; m <= 15; ++m) {
		vector <int> masks, calced_val;
		for (int i = 0; i < (1 << m); ++i) {
			int flag = 1;
			for (int j = 0; j < m; ++j) {
				if (bit (i, j) && j > 0 && bit (i, j - 1))
					flag = 0;
			}
			if (flag)
				masks.emplace_back (i);
		}
		vector <int> cango[masks.size ()];
		for (int i = 0; i < masks.size (); ++i) {
			for (int j = 0; j < masks.size (); ++j) {
				bool flag = 1;
				for (int k = 0; k < m; ++k) {
					int beat1 = (k > 0 && bit (masks[i], k - 1)) || bit (masks[i], k) || (k < m && bit (masks[i], k + 1));
					int beat2 = (k > 0 && bit (masks[j], k - 1)) || bit (masks[j], k) || (k < m && bit (masks[j], k + 1));
					if (beat1 && beat2)
						flag = 0;
				}
				if (flag)
					cango[i].emplace_back (j);
			}
		}
		for (int i = 0; i < masks.size (); ++i)
			calced_val.emplace_back (__builtin_popcount (masks[i]));
		memset (dp, 0, sizeof (dp));
		dp[1][0][0] = 1;
		for (int i = 1; i <= 16; ++i) {
			for (int j = 0; j <= i * m; ++j) {
				for (int k = 0; k < masks.size (); ++k) {
					if (!dp[i][j][k])
						continue;
					add (ans[i - 1][m][j], dp[i][j][k]);
					if (i == 16)
						continue;
					for (auto to : cango[k])
						add (dp[i + 1][calced_val[to] + j][to], dp[i][j][k]);
				}
			}
		}
		if (m == 2) {
			for (int i = 1; i <= 4; ++i) {
				for (int j = 0; j <= i * m; ++j) {
					for (int k = 0; k < masks.size (); ++k) {
						
						cerr << i << " " << j << " " << k << " -> " << dp[i][j][k] << "\n";
					}
				}
			}
		}
	}
	
	for (int i = 0; i <= 16; ++i)
		for (int j = 0; j <= 16; ++j)	
			for (int k = 0; k < 230; ++k)
				for (auto it : g[i][j][k])
					ansq[it] = ans[i][j][k];
		cerr << "\n";
	for (int i = 1; i <= t; ++i)
		cout << ansq[i] << " ";	
	return 0;
}