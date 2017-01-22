#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;

int a[20000], d;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, d;

	cin >> n >> d;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (binary_search (a + 1, a + n + 1, a[i] - d) && binary_search (a + 1, a + n + 1, a[i] + d))
			++ans;	
	}

	cout << ans;
	
	return 0;
}