#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

bool dp[N][2][3][3];

int p[3][N][2][3][3];

bool op[2][2];

int n, a[N];

inline void add (const int &i, const int &k1, const int &k2, const int &k3, const int &nk1, const int &nk2, const int &nk3) {
	dp[i + 1][nk1][nk2][nk3] = 1;
	p[0][i + 1][nk1][nk2][nk3] = k1;
	p[1][i + 1][nk1][nk2][nk3] = k2;
	p[2][i + 1][nk1][nk2][nk3] = k3;
}

int ans[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	op[0][0] = 1;
	op[0][1] = 1;
	op[1][0] = 0;
	op[1][1] = 1;
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cin >> n;
		
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n == 1) {
		if (a[1] == 0) {
			cout << "YES\n0";
		} else {
			cout << "NO\n";
		}
		return 0;
	}
	
	dp[1][1][2][2] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int k1 = 0; k1 < 2; ++k1)
		for (int k2 = 0; k2 < 3; ++k2)
		for (int k3 = 0; k3 < 3; ++k3) {			
			if (!dp[i][k1][k2][k3])
				continue;
			if (k2 == 2) {
				add (i, k1, k2, k3, op[k1][a[i]], k2, k3);
				add (i, k1, k2, k3, k1, 0, a[i]);
				add (i, k1, k2, k3, k1, a[i], k3);
			}
			else if (k3 == 2) {
				add (i, k1, k2, k3, k1, op[k2][a[i]], k3);
				add (i, k1, k2, k3, op[k1][op[k2][a[i]]], 2, k3);
				add (i, k1, k2, k3, k1, k2, a[i]);
			} else {
				add (i, k1, k2, k3, k1, k2, op[k3][a[i]]);
				add (i, k1, k2, k3, k1, op[k2][op[k3][a[i]]], 2);
				add (i, k1, k2, k3, op[k1][op[k2][op[k3][a[i]]]], 2, 2);
			}
		}
	}

	int fx1, fx2, fx3, j;

	fx1 = fx2 = fx3 = -1;
		
	for (int k1 = 0; k1 < 2; ++k1)
	for (int k2 = 0; k2 < 3; ++k2)
	for (int k3 = 0; k3 < 3; ++k3) {
		if (!dp[n + 1][k1][k2][k3])
			continue;
		if (k2 == 2) {
			if (k1 == 0) {
				fx1 = k1;
				fx2 = k2;
				fx3 = k3;
			}
		} else if (k3 == 2) {
			if (op[k1][k2] == 0) {
				ans[n + 1] = -1;
				fx1 = k1;
				fx2 = k2;
				fx3 = k3;
			}
		} else {
			if (op[k1][op[k2][k3]] == 0) {
				ans[n + 1] = -2;
				fx1 = k1;
				fx2 = k2;
				fx3 = k3;
			}
		}
	}
	
	if (fx1 == -1 && fx2 == -1 && fx3 == -1) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	
	for (int i = n + 1; i; --i) {
		int oldk1 = p[0][i][fx1][fx2][fx3], oldk2 = p[1][i][fx1][fx2][fx3], oldk3 = p[2][i][fx1][fx2][fx3];
		if (oldk2 == 2) {
			if (fx3 != 2) {
				ans[i] = 2;
			}
			if (fx2 != 2) {
				ans[i] = 1;
			}
		} else if (oldk3 == 2) {
			if (fx3 != 2) {
				ans[i] = 1;
			} else if (fx2 == 2) {
				ans[i] = -1;
			}

		} else {
			if (fx2 == 2) {
				ans[i] = -2;
			} else if (fx3 == 2) {
				ans[i] = -1;
			}
		}
		fx1 = oldk1;
		fx2 = oldk2;
		fx3 = oldk3;
	}
	
	for (int i = 1; i <= n + 1; ++i) {
		cerr << ans[i] << " ";
	}
	
	for (int i = 1; i < n; ++i) {
		if (ans[i] == -2) {
			cout << "((";
		} else if (ans[i] == -1) {
			cout << "(";
		}
		cout << a[i];
		if (ans[i] == 2) {
			cout << "))";
		} else if (ans[i] == 1) {
			cout << ")";
		}
		cout << "->";
	}
	
	if (ans[n] == -2) {
		cout << "((";
	} else if (ans[n] == -1) {
		cout << "(";
	}	
	cout << a[n];
	if (ans[n] == 2) {
		cout << "))";
	} else if (ans[n] == 1) {
		cout << ")";
	}
	
	return 0;
}