#include <bits/stdc++.h>

using namespace std;

int n, m, k;

map <int, int> Map;

inline int Grundy (const int &x) {
	if (Map.count (x))
		return Map[x];
	
	set <int> SL;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			int x1 = i, x2 = x / i;
			if (x1 != 1 && x2 >= k) {
				if (x1 & 1) {
					SL.insert (Grundy (x2));
				} else {
					SL.insert (0);
				}
			}
			if (x2 != 1 && x1 >= k) {
				if (x2 & 1) {
					SL.insert (Grundy (x1));
				} else {
					SL.insert (0);
				}
			}
		}
	}
	for (int i = 0;; ++i) {
		if (SL.find (i) == SL.end ()) {
			return Map[x] = i;
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m >> k;

	if (n & 1) {
		int x = Grundy (m);
		if (x == 0) {
			cout << "Marsel";
		} else {
			cout << "Timur";
		}
	} else {
		cout << "Marsel";
	}
	
	return 0;
}