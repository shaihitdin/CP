#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
 
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
 
	int t;
 
	scanf ("%d", &t);
 
	const double eps = 1.0 / 120;
 
	while (t--) {
		double x;
		scanf ("%lf", &x);
		for (int i = 0; i < 12; ++i) {
			double degree1 = i * 30;
			for (int j = 0; j < 60; ++j) {
				double degree2 = j * 6;
				double degree3 = degree1 + j * 0.5;
				double angle = min (max (degree3, degree2) - min (degree3, degree2), 
					360 - max (degree3, degree2) + min (degree3, degree2));
				if (fabs (x - angle) <= eps)
					printf ("%02d:%02d\n", i, j);
			}
		}
	}
 
	return 0;
} 