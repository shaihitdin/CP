/**
	Mom, I'm on someone's monitor!

**/

#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
	
	int t;
	cin >> t;

	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort (a + 1, a + n + 1);
		int ans = 0;
		for (int i = n, j = 1; i >= 1; --i) {
			int x = a[i];
			int k = (50 + x - 1) / x;
			--k;
			if (j + k - 1 >= i)
				break;
			++ans;
			j += k;
		}

		cout << ans << "\n";
	}

	return 0;
}