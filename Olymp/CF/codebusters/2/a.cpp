#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;

double a[N];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	double w;
	cin >> n >> w;

	for (int i = 1; i <= n + n; ++i) {
		cin >> a[i];
	}
	
	sort (a + 1, a + n + n + 1);
	cout << fixed;
	cout << setprecision (10);
	cout << min (min (a[1] * 3 * n, a[n + 1] / 2 * 3 * n), w);
	return 0;
}