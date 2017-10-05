#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int h, m;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d:%d", &h, &m);

	for (int ans = 0;; ++ans, ++m) {
		if (m == 60)
			m = 0, ++h;
		if (h == 24)
			h = 0;
		if (m % 10 == h / 10 && m / 10 % 10 == h % 10) {
			printf ("%d", ans);
			return 0;
		}
	}
	
	return 0;
}