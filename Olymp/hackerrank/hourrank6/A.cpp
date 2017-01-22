#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1 / 1e10;
ld ans;
ld r;

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m >> r;

	ld prob = 1;
	
	for (int d = 1; d <= 100; ++d) {
		if (prob < eps)	
			break;
		prob2 = 0;
		for (int i = 1; i <= n * m; ++i) {
			/// 
		}
		prob = prob2;
	}

	cout << ans;
	return 0;
}