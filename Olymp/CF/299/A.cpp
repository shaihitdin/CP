#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, n, l, t, m;

inline ll sum (const ll &f, const ll &diff, const int &num) {
	return (num * (2 * f + (num - 1) * diff)) / 2;
}

inline ll el (const int &pos) {
	return a + (pos - 1) * b;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);	
	
	cin >> a >> b >> n;

	for (int i = 1; i <= n; ++i) {
		
		cin >> l >> t >> m;
		
		int l_bin = l - 1, r_bin = 1e8;

		while (r_bin - l_bin > 1) {
			int mid = (r_bin + l_bin) >> 1;
			ll get = sum (el (l + m - 1), b * m, (mid - l + 1) / m);
			if ((mid - l + 1) % m != 0)
				get += (el (mid) - (el (mid - )));

			if (get > t)
				r_bin = mid;
			else
				l_bin = mid;
		}
		
		if (l_bin < l)
			cout << "-1\n";
		else
			cout << l_bin << "\n";
	}

	return 0;
}