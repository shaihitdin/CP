#include <bits/stdc++.h>

using namespace std;



inline bool ok (int x) {
	for (int i = 1; i <= n; ++i)
		
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int foo, bar;
		cin >> foo >> bar;
		g[foo].emplace_back (bar);
		g[bar].emplace_back (foo);
	}
	
	int l = 0, r = 1e6 + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (ok (mid))
			l = mid;
		else
			r = mid;
	}

	cout << l;
	
	return 0;
}