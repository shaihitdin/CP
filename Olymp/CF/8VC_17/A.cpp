/**
	I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

inline bool is_prime (int x) {
	if (x == 1)
		return 0;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	cin >> n;

	for (int m = 1; m <= 1000; ++m) {
		if (!is_prime (n * m + 1)) {
			cout << m;
			return 0;
		}
	}

	
	return 0;
}