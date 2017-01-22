/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 100;

struct vec {
	ld x, y;
	vec (ld val1, ld val2) {
		x = val1, y = val2;
	}
};

inline vec operator * (vec a, ld b) {
	return vec (a.x * b, a.y * b);
}

inline ld sqr (ld x) {
	return x * x;
}

inline ld dist (ld sx, ld sy, ld fx, ld fy) {
	return sqrt (sqr (fx - sx) + sqr (fy - sy));
}

/// For (x3, y3) -> (x2, y2)
inline ld solve (ld px, ld py, ld r, ld common, ld sx, ld fx) {
	if (py + r < common)
		return 0;
	ld lo = px, hi = fx;
	for (int cnt = 0; cnt < 60; ++cnt) {
		ld mid = (lo + hi) / 2;
		if (dist (px, py, mid, common) < r)
			lo = mid;
		else
			hi = mid;
	}
	ld calc = dist (px, py, lo, common);
	calc = (r / calc);
	ld v1 = vec ();
	
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> x[1] >> y[1] >> x[2] >> y[2];
	x[3] = x[1];
	y[3] = y[2];
	x[4] = x[2];
	y[4] = y[1];


	cin >> px >> py >> r;

	ans += solve () + solve () + solve (px, py, r, y[2], x[3], x[2]) + solve ();
	
	cout << fixed;
	cout << setprecision (10);
	
	cout << ans;
	
	return 0;
}