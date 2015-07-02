#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
const double eps = 1 / (1e6);


int test, n;

double a[N];

int main () {
    
    freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	scanf ("%d", &test);

	for (int t = 1; t <= test; ++t) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf ("%lf", &a[i]);
		
		double l = a[1] - eps, r = 1e4;
		while (r - l > eps) {
			double mid = (r + l) / 2;
			double now = a[1];
			bool flag = 0;
			for (int i = 2; i <= n; ++i) {
				if (now + a[i] <= mid)
					now += a[i];
				else
					now -= a[i];
				if (fabs (now) > mid) {
					flag = 1;
					break;
				}
				now = fabs (now);
			}
			if (flag)
				l = mid;
			else
				r = mid;
		}
		cerr << "OK";
		printf ("%.6lf\n", l);
	}


	return 0;
}