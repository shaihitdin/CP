#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct pt {
	ld x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int n, p, q;

inline ld f (ld t, ld xp, ld yp, ld xp2, ld yp2) {
	ld sx, sy;
	sx = t * xp;
	sy = t * yp;
	ld need = max ((p - sx) / xp2, (q - sy) / yp2);
	need = max (need, ld (0));
	return t + need;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> p >> q;

	vector <pt> v;

	int mxx = 0, mxy = 0;

	ld ans = 1e18;
	
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back ({ld (x), ld (y)});
		mxx = max (mxx, x);
		mxy = max (mxy, y);
		ans = min (ans, max (p / v[i].x, q / v[i].y));
	}
	
	v.push_back ({ld (mxx), ld (0)});
	v.push_back ({ld (0), ld (mxy)});

	convex_hull (v);
		
	for (int i = 1; i < v.size (); ++i) {
		ld l = 0, r = 1e8;
		for (int cnt = 0; cnt < 100; ++cnt) {
			ld mid1 = l + (r - l) / 3;
			ld mid2 = r - (r - l) / 3;
			if (f (mid1, v[i].x, v[i].y, v[i - 1].x, v[i - 1].y) < f (mid2, v[i].x, v[i].y, v[i - 1].x, v[i - 1].y))
				r = mid2;
			else
				l = mid1;
		}
		ans = min (ans, f (l, v[i].x, v[i].y, v[i - 1].x, v[i - 1].y));
	}
	
	
	cout << fixed;

	cout.precision (8);

	cout << ans;
	
	return 0;
}