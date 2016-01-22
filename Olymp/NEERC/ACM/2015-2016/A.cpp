#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("alex.in", "r", stdin);
	freopen ("alex.out", "w", stdout);

	double a, b;

	cin >> a >> b;

	double l = 0, r = max (a, b) + 1;

	for (int cnt = 0; cnt <= 40; ++cnt) {
		double mid = (r + l) / 2;
		if (mid * 3 < a && mid < b)
			l = mid;
		if (mid * 3 < b && mid < a)
			l = mid;
		if (mid * 2 < a && mid * 2 < b)
			l = mid;
		if (l != mid)
			r = mid;
	}

	cout << fixed;
	cout.precision (6);
	
	cout << l;
	
	return 0;
}