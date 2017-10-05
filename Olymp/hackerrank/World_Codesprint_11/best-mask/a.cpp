#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull ban[(1 << 21)];

inline bool bit (ull mask, int pos) {
	return (mask >> pos) & 1;
}

inline void or_val (int mask1, int mask2, ull val) {
	ban[mask1] |= (val << mask2);
}

inline void or_val (int mask, int val) {
	or_val (mask >> 6, ((mask >> 6) << 6) ^ mask, val);
}

inline bool get (int mask1, int mask2) {
	return bit (ban[mask1], mask2);
}

inline bool get (int mask) {
	return get (mask >> 6, ((mask >> 6) << 6) ^ mask);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	bool is_pow = 0;


	while (n--) {
		int x;
		cin >> x;
		if (x == (1 << 26)) {
			is_pow = 1;
			continue;
		}
		x ^= ((1 << 26) - 1);
		or_val (x, 1);
	}

	int ans = (1 << 29) - 1;
	
	for (int i = 0; i < 6; ++i) {
		for (int mask2 = 0; mask2 < (1 << 6); ++mask2) {
			if (bit (mask2, i)) {
				for (int mask1 = 0; mask1 < (1 << 20); ++mask1) {
					if (get (mask1, mask2)) {
						or_val (mask1, mask2 ^ (1 << i), 1);
					}
				}
			}
		}
	}

	for (int i = 0; i < 20; ++i) {
		for (int mask = 0; mask < (1 << 20); ++mask) {
			if (bit (mask, i)) {
				ban[mask ^ (1 << i)] |= ban[mask];
			}
		}
	}

	for (int mask = 0; mask < (1 << 26); ++mask)
		if (!get (mask))
			if (__builtin_popcount (mask) < __builtin_popcount (ans))
				ans = mask;
	
	if (is_pow)
		ans |= (1 << 26);


	cout << ans << "\n";
	
	cerr << clock () * 1000 / CLOCKS_PER_SEC << "\n";
	
	return 0;
}