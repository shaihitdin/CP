#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int n, a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = abs (a[i]);
	}

	for (int i = 1; i <= n; ++i) {
		int type1 (0), type2 (0);
		for (int j = 1; j < i; ++j) {
			if (a[j] > -a[i])
				++type1;
			if (a[j] > a[i])
				++type2;
		}
		for (int j = i + 1; j <= n; ++j) {
			if (-a[i] > a[j])
				++type1;
			if (a[i] > a[j])
				++type2;
		}
		if (type1 <= type2)
			a[i] = -a[i];
	}
	
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans += (a[i] > a[j]);
		}
	}
	
	cout << ans;
	
	return 0;
}