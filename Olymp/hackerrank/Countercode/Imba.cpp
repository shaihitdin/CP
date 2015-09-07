#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int l = n / 2, r = l + 1;
		while (1 <= l && r <= n) {
			if (n & 1) {
				cout << r << " " << l << " ";
			} else {
				cout << l << " " << r << " ";
			}
			--l, ++r;
		}
		if (n & 1)
			cout << r << " ";
		cout << "\n";
	}

	return 0;
}