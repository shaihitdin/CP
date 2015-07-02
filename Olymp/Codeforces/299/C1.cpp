#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int a[N], mx;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		a[i] = x + y;
		mx = max (mx, a[i]);
	}	

	for (int i = 1; i <= n; ++i)
		if (a[i] == mx)
			cout << i << " ";
	
	return 0;
}