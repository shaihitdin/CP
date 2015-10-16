#include <bits/stdc++.h>

using namespace std;

int a, b, c;

const double eps = 1 / 1e6;

map <int, int> Map;

inline int calc (int n) {
	if (Map.count (n))
		return Map[n];
	int coeff = a * b * c;
	int x = coeff / a, y = coeff / b, z = coeff / c;
	double ce = n / (1.0 * (x + y + z));
	if (int (ce * x + eps) > 0) {
		Map[n] = max (Map[n], a + calc (int (ce * x + eps)));
	}
	if (int (ce * y + eps) > 0) {
		Map[n] = max (Map[n], b + calc (int (ce * y + eps)));
	}
	if (n - int (ce * x + eps) - int (ce * y + eps) > 0) {
		Map[n] = max (Map[n], c + calc (n - int (ce * x + eps) - int (ce * y + eps)));
	}
	//cerr << n << " " << ce << " " << int (ce * x + 0.5 + eps) << " " << int (ce * y + 0.5 + eps) << " " << n - int (ce * x + 0.5 + eps) - int (ce * y + 0.5 + eps) << " " << Map[n] << "\n";

	return Map[n];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);


	int t;

	cin >> t;

	while (t--) {
		int n;
		cin >> n >> a >> b >> c;
		//cerr << "test\n";
		Map.clear ();
		Map[1] = 0;
		Map[0] = 0;
		if (a < c && a < b)
			swap (a, b);
		else if (b < c && b < a)
			swap (b, c);
		if (b > a)
			swap (a, b);
		cout << calc (n) << "\n";
	}
	
	return 0;
}