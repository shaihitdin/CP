/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

struct vc {
	double x, y;
};

inline double cross_product (const vc &a, const vc &b) {
	return (a.x * b.y - b.x * a.y);
}

int main () {
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
	int t;
    cin >> t;

    for (int test = 1; test <= t; ++test) {
    	cout << "Case #" << test << ": ";
    	double p, x, y;
    	cin >> p >> x >> y;
    	bool flag = (p == 100);
    	p = (2 * M_PI) * (p / 100);
    	p = (2 * M_PI) - p;
    	vc a, b, c;
    	x -= 50;
    	y -= 50;
    	a = {0, 50};
    	b = {a.x * cos (p) - a.y * sin (p), a.x * sin (p) + a.y * cos (p)};
    	c = {x, y};

    	if (x * x + y * y >= 2500) {
    		cout << "white\n";
    		continue;
    	}
    	if (flag == 1) {
    		cout << "black\n";
    		continue;
    	}
    	if ((cross_product (a, c) <= 0 && (cross_product (a, b) > 0 || cross_product (b, c) >= 0)) || (cross_product (a, c) >= 0 && cross_product (a, b) > 0 && cross_product (b, c) >= 0)) {
    		cout << "black\n";
    	} else {
    		cout << "white\n";
    	}
    }
	
	return 0;
}