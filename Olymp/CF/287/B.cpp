#include <bits/stdc++.h>
using namespace std;
double r, x[3], y[3], dist;
inline double sqr (const double &x) {
	return x * x;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> r >> x[1] >> y[1] >> x[2] >> y[2];
	dist = sqrt ( sqr(x[2] - x[1]) + sqr (y[2] - y[1]) );
	if (dist / (2 * r) != double ((int) (double (dist / (2 * r) ) ) ) )
		cout << (int) (dist / (2 * r)) + 1;
	else
		cout << (int) (dist / (2 * r));
	return 0;
}