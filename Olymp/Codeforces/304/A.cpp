#include <bits/stdc++.h>

using namespace std;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	long long k, n, w;

	cin >> k >> n >> w;

	cout << max (0ll, k * ((w * (w + 1)) / 2) - n);
	
	return 0;
}