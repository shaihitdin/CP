#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n, m, k;
int ans;
int u1[N], u2[N];
int a[11][11];

inline void rec (int x, int y) {
	if (x == n + 1) {
		for (int ss = 1; ss < m; ++ss) {
			memset (u1, 0, sizeof (u1));
			memset (u2, 0, sizeof (u2));
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= ss; ++j) {
					u1[a[i][j]] = 1;
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = ss + 1; j <= m; ++j) {
					u2[a[i][j]] = 1;
				}
			}
			int cnt1 = 0, cnt2 = 0;
			for (int i = 1; i <= k; ++i) {
				cnt1 += u1[i];
				cnt2 += u2[i];
			}
			if (cnt1 != cnt2)
				return;
		}
		++ans;
/*
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
*/
		return;
	}
	if (y == m + 1) {
		rec (x + 1, 1);
		return;
	}
	for (int i = 1; i <= k; ++i) {
		a[x][y] = i;
		rec (x, y + 1);
	}
}

typedef long long ll;

const ll bpr = 1e9 + 7;

ll dp[1100][1100];
ll f[1100];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;

	
	dp[0][0] = 1;

	for (int i = 1; i < 1100; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (((dp[i - 1][j] * j) % bpr) + dp[i - 1][j - 1]) % bpr;
		}
	}
	
	cerr << "OK";
	
	cerr << (dp[3][2]) % bpr << "\n";

/*	
	cin >> n >> m >> k;	
	rec (1, 1);
	
	cout << ans;
*/	
	return 0;
}