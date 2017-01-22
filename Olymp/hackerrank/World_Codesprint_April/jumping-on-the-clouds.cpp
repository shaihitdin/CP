#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;

int c[200], d[200];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> c[i];

	for (int i = 1; i < n; ++i)
		d[i] = oo;
	
	d[0] = 0;

	for (int i = 0; i < n; ++i) {
		if (c[i])
			d[i] = oo;
		d[i + 1] = min (d[i + 1], d[i] + 1);
		d[i + 2] = min (d[i + 2], d[i] + 1);
	}	
	
	cout << d[n - 1];
	
	return 0;
}