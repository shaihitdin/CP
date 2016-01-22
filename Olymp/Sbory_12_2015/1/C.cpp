#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, oo = 1e9 + 7;

int n, m, ans;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline bool inside (int x) {
	return x >= 0 && x < m;
}

//return ants without heap
inline int can (int mask1, int mask2) {
	int ret_val = 0;
	for (int i = 0; i < m; ++i) {
		if (inside (i - 1) && bit (mask2, i - 1)) {
			continue;
		} else if (bit (mask2, i)) {
			continue;
		} else if (inside (i + 1) && bit (mask2, i + 1)) {
			continue;
		} else if (bit (mask1, i)) {
			continue;
		} else {
			ret_val |= (1 << i);
		}
	}
	return ret_val;
}

int d[50][68][68];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	if (n == 1 && m == 1) {
		cout << 0;
		return 0;
	}
	
	if (n < m)
		swap (n, m);
	
	for (int i = 0; i < n; ++i)
		for (int mask1 = 0; mask1 < (1 << m); ++mask1)
			for (int mask2 = 0; mask2 < (1 << m); ++mask2)
				d[i][mask1][mask2] = oo;
	
	for (int mask = 0; mask < (1 << m); ++mask) {
		d[0][can (0, mask)][mask] = __builtin_popcount (can (0, mask)) + __builtin_popcount (mask);
	}	
	
	for (int i = 1; i < n; ++i) {
		for (int mask1 = 0; mask1 < (1 << m); ++mask1) { // left ants
			for (int mask2 = 0; mask2 < (1 << m); ++mask2) { // last mask
				for (int mask3 = 0; mask3 < (1 << m); ++mask3) { // new mask
					d[i][can (mask2, mask3)][mask3] = min (d[i][can (mask2, mask3)][mask3], d[i - 1][mask1][mask2] - __builtin_popcount (mask1 & mask3) + 
					__builtin_popcount (can (mask2, mask3)) +
					__builtin_popcount (mask3));
				}
			}
		}
	}
	
	for (int mask1 = 0; mask1 < (1 << m); ++mask1)
		for (int mask2 = 0; mask2 < (1 << m); ++mask2)
			ans = max (ans, n * m - d[n - 1][mask1][mask2]);
				
	cout << ans;
	
	return 0;
}