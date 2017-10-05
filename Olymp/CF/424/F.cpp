#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 110;

int n, k, a[N];

inline int min_divisor (int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0)
			return i;
	}
	return x;
}

inline bool check (int x) {
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += (x - (a[i] % x)) % x;
	}
	return res <= k;
}

main () {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    	cin >> a[i];

    sort (a + 1, a + n + 1);

	ll ans = 1;
	for (int i = 1; i <= 1e5; ++i) {
		if (check (i))
			ans = max (ans, i);
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = max (1ll, a[i] - 1000); j <= a[i] + 1000; ++j) {
			if (check (j))
				ans = max (ans, j);
		}
	}
	
	
	ll pen = 0;
	for (int i = 1; i <= n; ++i) {
		pen += abs (a[i] - a[n]);
	}
	
	for (int i = max (1ll, a[n] + (k - pen) / n - 1000); i <= a[n] + (k - pen) / n + 1000; ++i) {
		if (check (i))
			ans = max (ans, i);	
	}
	
	cout << ans;
	
	return 0;
}