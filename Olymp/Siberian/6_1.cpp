#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n;

	const long double eps = 1 / 1e10;
	
	cin >> n;

	cin.precision (6);
	
	while (n--) {
		long double x, y, z;
		cin >> x >> y >> z;
		if (x < y) swap(x, y);
		if (y < z) swap(y, z);
		if (x < y) swap(x, y);

		z /= x;
		y /= x;
		x = 1;
		cerr << x << " " << y << " " << z << " " << (x + y + z) / 3 << "\n";
	//	puts ((sx < coeff /*&& fabs (coeff - sx) > eps*/) ? "YES" : "NO");
	}

	return 0;
}