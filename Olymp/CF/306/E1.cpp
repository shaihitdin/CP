#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, a[N], ans[N];

bool op[2][2];

inline void no () {
	cout << "NO\n";
	exit (0);
}

inline void yes () {
	cout << "YES\n";
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
	exit (0);
}

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

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		if (a[1] == 0) {
			cout << "YES\n0";
		} else if (a[1] == 1) {
			no ();
		}
		return 0;
	}
	
	if (n == 2) {
		if (a[1] == 1 && a[2] == 0) {
			cout << "YES\n1->0";
		} else {
			no ();
		}
		return 0;
	}
	
	if (a[n] == 0) {
		if (a[n - 1] == 0) {
			int now = a[1];
			int res;
			for (int i = 2; i <= n; ++i) {
				now = op[now][a[i]];
				if (i == n - 3) {
					res = now;
				}
			}
			if (now == 0) {
				yes ();
			} else {
				if (n > 3) {
					ans[n - 2] = -1;
					[n - 1] = 1;
					yes ();
				} else {
					no ();
				}
			}
		}
	} else {
		no ();
	}
	
	return 0;
}