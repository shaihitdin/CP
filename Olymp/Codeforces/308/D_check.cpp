#include <bits/stdc++.h>

using namespace std;

const double eps = 0.5;

long long cnt;

double x1, x2;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int n = 2000;
	
	

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k, ++cnt)
				if (x1 < x2) x1 += eps;
				else x2 += eps;

	cout << cnt;
	
	fprintf (stderr, "%d", clock () * 1000 / CLOCKS_PER_SEC);

	return 0;
}