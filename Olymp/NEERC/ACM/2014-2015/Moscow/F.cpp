#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1 / 1e7;

inline ld dist (const int &sx, const int &sy, const int &fx, const int &fy) {
	return sqrt ((abs (sx - fx) * abs (sx - fx)) + (abs (sx - fx) * abs (sx - fx)))
}


int main () {

	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	cin >> d >> v;
	d *= 60;
	ld ans1 = (dist (xa, ya, xc, yc)) / ld (v / 3600.0);
	ans1 += (dist (xc, yc, xa, ya)) / ld (v / 3600.0);
	ans1 += d;
	
	int time1, time2, time3, time4;
	
	scanf ("%d:%d %d:%d", &time1, &time2, &time3, &time4);
	
	ans2 = 9
	
	return 0;
}