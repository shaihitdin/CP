#include <bits/stdc++.h>

using namespace std;

long double m, n;

long double ans;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> m >> n;
	for (double i = 1; i <= m; i += 1)
		ans += (i * (pow (i / m, n) - pow ((i - 1) / m, n) ) );
	cout.precision (5);
	cout << fixed;
	cout << ans;
	return 0;
}