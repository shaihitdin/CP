#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int n, q;

int mult[N], occ[2][N], a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i) {
		if (occ[0][a[i]] == 0)
			occ[0][a[i]] = i;
		else
			occ[1][a[i]] = i;
	}
	
	mult[0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 3)
			mult[i] = mult[i - 1];
		else
			mult[i] = (mult[i - 1] * (a[i] % 3)) % 3;
	}
	
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l <= occ[0][3] && occ[1][3] <= r) {
			if (l == 1)
				cout << mult[r] << "\n";
			else
				cout << (mult[r] * mult[l - 1]) % 3 << "\n";
		} else if (l <= occ[0][3] && occ[0][3] <= r) {
			cout << 0 << "\n";
		} else if (l <= occ[1][3] && occ[1][3] <= r) {
			cout << 0 << "\n";
		} else {
			if (l == 1)
				cout << mult[r] << "\n";
			else
				cout << (mult[r] * mult[l - 1]) % 3 << "\n";
		}
	}
	
	return 0;
}