#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> x;
		upd (root, 1, n, i, i, 1, x, -inf);
	}

	while (m--) {
		cin >> q_type;
		if (q_type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			upd (root, 1, n, l, r, x, 0, -inf);
		} else if (q_type == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			upd (root, 1, n, l, r, 1, x, -inf);
		} else if (q_type == 3) {
			int l, r, x;
			cin >> l >> r >> x;
			upd (root, 1, n, l, r, 1, 0, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << get (root, 1, n, l, r) << "\n";
		}
	}
	
	return 0;
}