#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q;

inline ll calc (const int &k) {
	return n * 1ll * (n / k) + k * 31ll * q;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	cin >> n >> q;

	int l = 0, r = n + 1;

	while (r - l > 10) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (calc (mid1) < calc (mid2)) {
			r = mid2;
		} else {
			l = mid1;
		}
	}

	int now = l;

	
	for (; l <= r; ++l)
		if (calc (now) > calc (l))
			now = l;
	
	cout << now << " " << calc (now);

	return 0;
}