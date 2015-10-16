#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int d[10001];
int t;

inline int rec (const int &n) {
	if (d[n] != -1)
		return d[n];
	d[n] = 1e9;
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int dif = 0;
			if (i > 0) {
				dif = max (dif, rec (i) + a);
			}
			if (i != j) {
				dif = max (dif, rec (j - i) + b);
			}
			if (j != n) {
				dif = max (dif, rec (n - j) + c);
			}
			d[n] = min (d[n], dif);
		}
	}
	return d[n];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> t;

	while (t--) {
		int n;
		cin >> n >> a >> b >> c;
		memset (d, -1, sizeof (d));
		d[0] = 0;
		d[1] = 0;
		cout << rec (n) << "\n";
	}	

	return 0;
}