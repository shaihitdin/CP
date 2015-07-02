#include <bits/stdc++.h>

using namespace std;

struct pt {
	double x, y;
};

const int N = 20;

pt b[N];
int ans[N];


inline bool cmp (const pt &a, const pt &b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cw (const pt &a, const pt &b, const pt &c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

inline bool ccw (const pt &a, const pt &b, const pt &c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

inline vector <pt> convex_hull (vector <pt> a) {
	
	if (a.size() == 1)
		return a;

	sort (a.begin(), a.end(), &cmp);

	pt p1 = a[0],  p2 = a.back ();
	
	vector <pt> up, down;
	up.push_back (p1);
	down.push_back (p1);

	for (int i = 1; i < a.size(); ++i) {
		if (i + 1 == a.size() || cw (p1, a[i], p2)) {
			while (up.size() >= 2 && !cw (up[up.size() - 2], up[up.size() - 1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i + 1 == a.size() || ccw (p1, a[i], p2)) {
			while (down.size() >= 2 && !ccw (down[down.size() - 2], down[down.size() - 1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	
	a.clear();
	
	for (int i = 0; i < up.size(); ++i)
		a.push_back (up[i]);
	
	reverse (down.begin (), down.end ());
	
	for (int i = 1; i < down.size (); ++i)
		a.push_back (down[i]);

	return a;
}


inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	int t;

	cin >> t;

	for (int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x, y;
			cin >> x >> y;
			b[i] = {double (x), double (y)};
		}


		for (int i = 1; i <= n; ++i)
			ans[i] = n - 1;
		
		for (int i = 1; i < (1 << n); ++i) {
			int cnt = 0;
			vector <pt> a;
			a.resize (0);
			for (int j = 0; j < n; ++j)
				if (bit (i, j))
					a.push_back (b[j + 1]);
				else
					++cnt;
			a = convex_hull (a);
			for (int j = 1; j <= n; ++j)
				for (int k = 0; k < a.size (); ++k)
					if (b[j].x == a[k].x && b[j].y == a[k].y)
						ans[j] = min (ans[j], cnt);
		}

		cout << "Case #" << test << ":\n";
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << "\n";
	}

	return 0;

}