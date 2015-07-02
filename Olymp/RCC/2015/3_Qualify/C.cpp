#include <bits/stdc++.h>

using namespace std;

int test;
int a1, a2, b1, b2, z;

int main () {

	//freopen ("in", "r", stdin);
	//freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio(0);

	cin >> test;

	while (test--) {
		cin >> a1 >> b1 >> a2 >> b2 >> z;
		int x = 0, y = 0;
		int nx, ny;
		double ans = 0.0;
		for (int t = 1; t <= z; ++t, x = nx, y = ny) {
			int vx, vy;
			if (((t - 1) / 12) & 1) {
				vx = -b1, vy = -b2;
			} else {
				vx = a1, vy = a2;
			}
			nx = x + vx;
			ny = y + vy;
			if (x <= y && nx <= ny)
				continue;
			if ((x >= y && nx >= ny)) {
				ans += 1;
				continue;
			}
			if (x == y)	continue;
			if (nx == ny)	continue;
			double te = double (x - y) / double (vy - vx);
			if (x >= y) ans += te;
			else ans += 1.0 - te;
		}
		cout << fixed << setprecision(10) << ans << "\n";
	}

	return 0;
}