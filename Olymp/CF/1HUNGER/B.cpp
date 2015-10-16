#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int n, q;
ll a[N], d1[N], d2[N];

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

	for (int i = 1; i <= n; ++i)
		d1[i] = d1[i - 1] + (((i & 1) ? -1 : 1) * a[i]);
	for (int i = 1; i <= n; ++i)
		d2[i] = d2[i - 1] + (((i & 1) ? 1 : -1) * a[i]);
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l & 1) {
			cout << d2[r] - d2[l - 1] << "\n";
		} else {
			cout << d1[r] - d1[l - 1] << "\n";
		}
	}
	
	return 0;
}