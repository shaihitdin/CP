#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		if (y[i] & 1)
			swap (x[i], y[i]);
		
	}
	return 0;
}