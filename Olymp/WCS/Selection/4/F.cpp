/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 100;

inline bool limit (ll a, ll b) {
	return a * 1.0 * b <= 2e18;
}

inline bool limit (ld a) {
	return a <= 2e18;
}

inline ll bin_pow (ll a, int b) {
	if (!b)
		return 1;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	ll c = bin_pow (a, b / 2);
	return c * c;
}

ll n;

inline bool Find (int i, int j, int k) {
	ll l = 1, r = 1e18;
	while (r - l > 1) {
		ll mid = (r + l) / 2;
		if (limit (pow (mid, i) + pow (mid, j) + pow (mid, k))) {
			if (bin_pow (mid, i) + bin_pow (mid, j) + bin_pow (mid, k) <= n)
				l = mid;
			else
				r = mid;
		} else {
				r = mid;
		}
	}
	return (bin_pow (l, i) + bin_pow (l, j) + bin_pow (l, k) == n);
	
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	
	int ans = 0;
	
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j < 60; ++j) {
			for (int k = 0; k < 60; ++k) {
			}
		}
	}
	
	
				
	int ans1 = 0, ans2 = 0, ans3 = 0;
	/*	
	for (int i = 0; i < 60; ++i)
		for (int j = 0; j < 60; ++j)
			for (int k = 0; k < 60; ++k)
				ans3 += Find (i, j, k);
	*/
	for (int i = 0; i < 60; ++i)
		for (int j = i + 1; j < 60; ++j)
			for (int k = j + 1; k < 60; ++k)
				ans1 += Find (i, j, k);
	for (int i = 0; i < 60; ++i) {
		for (int j = i + 1; j < 60; ++j) {
			ans2 += Find (i, i, j);
			ans2 += Find (i, j, j);
		}
	}
	for (int i = 0; i < 60; ++i)
		ans3 += Find (i, i, i);

	cout << ans1 * 6 + ans2 * 3 + ans3;
	
	return 0;
}