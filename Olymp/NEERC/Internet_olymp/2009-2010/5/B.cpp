#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

bool flag = 0;

inline void print (const ld &a, const ld &b, const ld &a1, const ld &b1) {
	int val1 = (a < 0) ? (a - 0.5) : (a + 0.5), val2 = (b < 0) ? (b - 0.5) : (b + 0.5);
	if (!flag)
		cout << val1 << " " << int (a1) << "\n" << val2 << " " << int (b1);
	else
		cout << val2 << " " << int (b1) << "\n" << val1 << " " << int (a1);
	exit (0);
}

int main () {

	freopen ("balls.in", "r", stdin);
	freopen ("balls.out", "w", stdout);

	ld x1, v1, x2, v2, T;
	
	cin >> x1 >> v1 >> x2 >> v2;

	cin >> T;
	
	if (x1 > x2)
		swap (x1, x2), swap (v1, v2), flag ^= 1;

	ld dist = fabs (x1 - x2);

	if (v1 < 0) {
		if (v2 < v1) {
			ld t = dist / (fabs (v2) - fabs (v1));
			if (T < t) {
				print (x1 + v1 * T, x2 + v2 * T, v1, v2);
			} else {
				ld inter_point = x1 + v1 * t;
				print (inter_point + v2 * (T - t), inter_point + v1 * (T - t), v2, v1);
			}
		} else {
			print (x1 + v1 * T, x2 + v2 * T, v1, v2);		
		}
	} else {
		if (v2 < v1) {
			ld t = dist / (v1 - v2);
			if (T < t) {
				print (x1 + v1 * T, x2 + v2 * T, v1, v2);
			} else {
				ld inter_point = x1 + v1 * t;
				print (inter_point + v2 * (T - t), inter_point + v1 * (T - t), v2, v1);
			}
		} else {
			print (x1 + v1 * T, x2 + v2 * T, v1, v2);		
		}
	}

	return 0;
}