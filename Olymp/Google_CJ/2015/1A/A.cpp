#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int a[N];

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int t;
	
	cin >> t;

	for (int test = 1; test <= t; ++test) {
		
		int n;

		cin >> n;

		int ans = 0, check = 0;

		cout << "Case #" << test << ": ";
		
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			ans += max (0, a[i - 1] - a[i]);
		}
		
		cout << ans << " ";
		
		ans = 0;

		for (int i = 2; i <= n; ++i)
			check = max (check, a[i - 1] - a[i]);		
		
		for (int i = 1; i < n; ++i)
			ans += min (a[i], check);
		
		cout << ans << "\n";
	}

	return 0;
}