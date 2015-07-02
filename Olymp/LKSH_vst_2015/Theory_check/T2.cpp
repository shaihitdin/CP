#include <bits/stdc++.h>

using namespace std;

#define y1 works

inline bool check (const double &x, const double &y, const double &x1, const double &x2, const double &y1, const double &y2) {
	return (x + y + x1 + x2 + y1 + y2 == 1) && ((0.6 * y1) + (0.6 * y) < (0.4 * x) + (0.4 * x1)) && ((0.6 * y2) + (0.6 * y) < (0.4 * x) + (0.4 * x2));
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	/// 1
	/*	
	for (double y1 = 0; y1 <= 1; y1 += 0.01) {
		for (double y2 = 0; y2 <= 1; y2 += 0.01) {
			double x = 1 - y1 - y2;
			if (x < 0 || y1 + y2 < x)
				continue;

			if (check (x, 0.0, 0.0, 0.0, y1, y2)) {
				cout << x << " " << y1 << " " << y2 << "\n";
			}
		}
	}
	*/

	cerr << check (0, 0.1, 0.25, 0.65, 0, 0);

	/// 8
	for (double y1 = 0; y1 <= 1; y1 += 0.01) {
		for (double y2 = 0; y2 <= 1; y2 += 0.01) {
			for (double x = 0; x <= 1; x += 0.01) {
				if (check (x, 0, 0, 0, y1, y2) && y1 + y2 >= 0.6) {
					cout << y1 << " " << y2 << " " << x << "\n";
				}
			}
		}
	}
	return 0;
}