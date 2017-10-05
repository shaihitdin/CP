#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 100;

#define int ll

int a[N], u[N];

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	int discount = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (discount >= a[i]) {
			u[i] = 1;
			discount -= a[i];
		} else {
			ans += 
		}
	}
	
	return 0;
}