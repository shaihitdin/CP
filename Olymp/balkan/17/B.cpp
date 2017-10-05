#include <bits/stdc++.h>

using namespace std;


vector <int> sides;

inline void rec (int x, int y, int k) {
		if (k == 0)
			return;
		int side = 0;
		if (x <= (1 << (k - 1)) && y <= (1 << (k - 1))) {
			side = 1;
		} else if (x <= (1 << (k - 1))) {
			y -= (1 << (k - 1));
			side = 2;
		} else if (y <= (1 << (k - 1))) {
			x -= (1 << (k - 1));
			side = 3;
		} else {
			x -= (1 << (k - 1));
			y -= (1 << (k - 1));
			side = 4;
		}
		sides.emplace_back (side);
		rec (x, y, k - 1);
}

int ps[10][10] = {{}, {1, 3, 4, 2}, {2, 4, 3, 1}, {3, 1, 2, 4}, {4, 2, 1, 3}};

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t;

	cin >> t;

	while (t--) {
		int test, k, v;
		cin >> test >> k >> v;
		assert (k <= 12);
		if (test == 1) {
			sides.clear ();
			int x = (v - 1) / (1 << k) + 1, y = (v - 1) % (1 << k) + 1;
			int side = 0;
			rec (x, y, k);		
			if (k == 1) {
				for (int i = 0; i < 4; ++i) {
					if (ps[1][i] == v) {
						cout << i + 1 << "\n";
					}
				}
				continue;
			}

			side = sides[0];
			sides.erase (sides.begin ());
			int delta = (1 << (k - 1));
			delta *= delta;
			int ans = 0;
			for (int i = 0; i + 1 < sides.size (); ++i, delta /= 4) {
				for (int j = 0; j < 4; ++j) {
					if (ps[side][j] == sides[i]) {
						ans += delta * j;
					}
				}
			}
			for (int i = 0; i < 4; ++i) {				
				if (sides.back () == ps[side][i]) {
					if (i == 0) {
						for (int j = 0; j < 4; ++j)
							if (ps[1][j] == side)
								ans += j;
					}
					if (i == 1) {
						for (int j = 0; j < 4; ++j)
							if (ps[2][j] == side)
								ans += j;
						ans += 4;					
					}
					if (i == 2) {
						for (int j = 0; j < 4; ++j)
							if (ps[1][j] == side)
								ans += j;					
						ans += 8;
					}
					if (i == 3) {
						for (int j = 0; j < 4; ++j)
							if (ps[2][j] == side)
								ans += j;
						ans += 12;					
					}
				}
			}
			++ans;
			cout << ans << "\n";
		} else {
			assert (0);
		}
	}


	return 0;
}