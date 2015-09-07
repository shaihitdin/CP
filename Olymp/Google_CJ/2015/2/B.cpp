#include <bits/stdc++.h>

using namespace std;


typedef double ld;

const int N = 101;

ld r[N], c[N], coeff[N][N], u_time[N];
int n;
ld v, x;
ld a[N];
vector <int> s1, s2, s3;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	int t;

	scanf ("%d", &t);

	for (int test = 1; test <= t; ++test) {
		printf ("Case #%d: ", test);
		scanf ("%d%lf%lf", &n, &v, &x);
		for (int i = 1; i <= n; ++i)
			scanf ("%lf%lf", &r[i], &c[i]);

		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (c[i] > c[j]) {
					swap (c[i], c[j]);
					swap (r[i], r[j]);
				}
			}
		}
		
		for (int i = 1; i <= n; ++i)
			c[i] -= x;
		
		s1.resize (0);
		s2.resize (0);
		s3.resize (0);
		
		for (int i = 1; i <= n; ++i) {
			if (c[i] < 0)
				s1.emplace_back (i);
			else if (c[i] == 0)
				s2.emplace_back (i);
			else
				s3.emplace_back (i);
		}
		
		reverse (s1.begin (), s1.end ());
		
		/*
		for (auto i : s1) {
			for (auto j : s3) {
				assert (x * r[j] - r[j] * c[j] != 0);
				coeff[i][j] = (r[i] * c[i]) / (- r[j] * c[j]);
				assert (coeff[i][j] != 0);
			}
		}
		*/
		ld l_mid = 0, r_mid = 1e20;

		for (int cnt = 0; cnt < 500; ++cnt) {
			ld mid = (r_mid + l_mid) / 2;
			ld now = 0;
			for (int i = 1; i <= n; ++i)
				a[i] = r[i] * mid;
			for (auto i : s2) {
				now += a[i];
				a[i] = 0;
			}
			//for (int k = 0; k <= n / 2; ++k) {
				for (auto i : s1) {
					for (auto j : s3) {
						ld z = min (a[j] / (-c[i]), a[i] / c[j]);
						now += z * (-c[i]) + z * c[j];
						a[j] -= z * (-c[i]);
						a[i] -= z * c[j];
						
					}
				}
			//}
			if (now >= v)
				r_mid = mid;
			else
				l_mid = mid;
		}
		if (l_mid > 1e19) {
			printf ("IMPOSSIBLE");
		} else {
			printf ("%.9lf", l_mid);
		}
		printf ("\n");
	}
	
	
	return 0;
}