#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
const long double eps = 0.00000000001;
long double x, y, z, l, r, mid;
int n;
inline int eq (const long double &a, const long double &b) {
	if (max (a, b) - eps < min(a, b))
		return 0;
	//cerr << a << " " << b << "\n";
	if (a < b)
		return 1;	
	return 2;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> z;
		l = 0;
		r = z;
		while (r - l > eps) {
			mid = (r + l) / 2.0;
			if ( (long long) ((long double) (mid / (1 / x) )) + (long long) ((long double) (mid / (1 / y))) < z)
				l = mid;
			else
				r = mid;
		}
		bool flag1 = 0, flag2 = 0;
		long long ans = eq ( ((long long) ((long double) (l / (1 / x) ) ) + 1) * (1 / x), ( ( (long long) ((long double) (l / (1 / y) ) ) + 1) ) * (1 / y) );
		if (ans == 0)
			puts ("Both");
		if (ans == 1)
			puts ("Vanya");
		if (ans == 2)
			puts ("Vova");
	}
	return 0;
}