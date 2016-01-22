#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("lucky.in", "r", stdin);
	freopen ("lucky.out", "w", stdout);
	
	int l, r, n, m;
	
	cin >> n >> m;

	r = n;
	l = n - m;

	assert (n > m);
	
	int ans = 0;
	
	for (int i = 1; i <= 9; ++i) {
		long long x = i;
		for (int j = 1; j <= 10; ++j) {
			if (l <= x && x <= r)
				++ans;
			
			x *= 10;
			x += i;
		}
	}
	
	cout << ans;
	
	return 0;
}