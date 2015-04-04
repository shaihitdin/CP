#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
//const long double eps = 1 / (1e18);
long long x[4], y[4], a, b, xx;
long long distx, disty;

int main () {
	freopen ("stair.in", "r", stdin);
	freopen ("stair.out", "w", stdout);
	cin >> x[1] >> y[1] >> x[2] >> y[2] >> a >> b;
	distx = abs (x[1] - x[2]);
	disty = abs (y[1] - y[2]);	
	long long old_distx = distx, old_disty = disty;
	distx *= disty;
	a *= disty;
	disty *= old_distx;
	b *= old_distx;
	xx = (distx / a);
	long double hh, hu, hd;
	hh = (long double) distx / xx;
	hu = b;
	hd = a;
	if ((hu >= hh /*|| (max (hu, hh) - min (hu, hh) < eps)*/) && (hd <= hh /*|| (max (hd, hh) - min (hd, hh) < eps)*/)) {
		
		cout << old_distx << " " << xx << "\n" << old_disty << " " << xx;
	}
	else {
		cout << -1;
	}
	return 0;
}