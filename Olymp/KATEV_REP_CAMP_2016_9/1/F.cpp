/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m, k;

	cin >> n >> m >> k;

	int a[n + 1];
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n % 2 == 0) {
		cout << 0;
		return 0;
	}
	
	int mv = (n + 1) / 2;
	int pb = m / mv;
	int some_val = 1e9;

	for (int i = 1; i <= n; i += 2)
		some_val = min (some_val, a[i]);
	
	cout << min (some_val * 1ll, pb * 1ll * k);
	
	return 0;
}