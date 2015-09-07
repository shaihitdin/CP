#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int wr, hr, wt, ht, swr, shr, swt, sht;

	cin >> wr >> hr >> wt >> ht;
	swr = wr, shr = hr, swt = wt, sht = ht;
	
	int ans = 0;
	while (wr > 0) {
		int tile = wt / min (wr, wt);
		cerr << hr << " " << tile << " " << ht << "\n";
		ans += (hr / tile / ht) + ((hr % (ht * tile)) > 0);
		wr -= wt;
	}
	
	int ans2 = 1e9;
	wr = shr, hr = swr, wt = sht, ht = swt;

	/*
	while (wr > 0) {
		int tile = wt / min (wr, wt);
		ans2 += (hr / tile / ht) + ((hr % (ht * tile)) > 0);
		wr -= wt;
	}
	*/
	cout << min (ans, ans2);
	
	return 0;
}