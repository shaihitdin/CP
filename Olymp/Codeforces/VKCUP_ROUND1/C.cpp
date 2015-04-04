#include <bits/stdc++.h>

using namespace std;

const int N = 6001;

typedef long long ll;


set <int> Set;

int n, k, a[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		Set.insert (a[i]);
	int q;
	cin >> q;
	for (int test = 1; test <= q; ++test) {
		int x;
		cin >> x;
		int ans = k + 1;
		for (int i = 1; i <= n; ++i)
			if (x % a[i] == 0)
				ans = min (ans, x / a[i]);
		for (int k1 = 1; k1 <= k; ++k1)
			for (int i = 1; i <= n; ++i)
				for (int k2 = 1; k1 + k2 <= k; ++k2)
					if ((x - a[i] * k1) % k2 == 0 && Set.find ((x - a[i] * k1) / k2) != Set.end())
						ans = min (ans, k1 + k2);
		if (ans == k + 1)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}