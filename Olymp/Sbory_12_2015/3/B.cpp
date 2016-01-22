#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m, a[N];

int main () {

	freopen ("army.in", "r", stdin);
	freopen ("army.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	a[0] = -1;
	a[n + 1] = 1e9 + 1;
	int ok = 0;
	for (int i = 1; i <= n + 1; ++i) {
		ok += (a[i] >= a[i - 1]);
	}
	
	while (m--) {
		char q_type;
		cin >> q_type;
		if (q_type == '?') {
			if (ok == n + 1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			int x, y;
			cin >> x >> y;
			ok -= (a[x] >= a[x - 1]);
			ok -= (a[x + 1] >= a[x]);
			a[x] = y;
			ok += (a[x] >= a[x - 1]);
			ok += (a[x + 1] >= a[x]);
		}
	}
	
	return 0;
}