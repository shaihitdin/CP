#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, a[N];

int main () {

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	while (m--) {
		int l, r;
		int res = 0;
		cin >> l >> r;
		for (int i = l; i <= r; ++i)
			res += a[i];
		ans += max (res, 0);
	}	

	cout << ans;
	return 0;
}