#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;

set <double> s;

double x0, y0, x[N], y[N];
int n;

int main () {	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> x0 >> y0;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		if (y[i] - y0 == 0)
			s.insert ((y[i] - y0) / (x[i] - x0));
		else
			s.insert ((x[i] - x0) / (y[i] - y0));
	}
	cout << s.size();
	return 0;
}