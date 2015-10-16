#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
const ll oo = -1e18 - 2;

ll b[N], a[N];
int n;

inline int it (int x) {
	if (x < 0)
		x += n;
	if (x >= n)
		x -= n;
	return x;
}

inline ll calc2 () {
	ll l = -1e9 - 2, r = 1e9 + 2;
	while (r - l > 1) {
		ll mid = (r + l) / 2;

	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf ("%I64d", &b[i]);
	}	
	
	if (n % 3 == 0) {
		assert (n <= 6);
		for (int i = 0; i < n; ++i) {
			if (b[0] != b[i]) {
				printf ("-1");
				return 0;
			}
		}
		if (b[0] > 3e9) {
			printf ("-1");
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			if (i % 3 == 0) {
				printf ("%d ", b[0] / 3);
			} else if (i % 3 == 1) {
				printf ("%d ", b[0] / 3 + (b[0] % 3 > 0));
			} else {
				printf ("%d ", b[0] / 3 + (b[0] % 3 > 1));
			}
		}
		return 0;
	}
	
	for (int i = 0; i < n; ++i)
		a[i] = oo;
	
	int i = 0;
	for (a[i] = 0; a[it (i - 3)] == oo; i = it (i - 3))
		a[it (i - 3)] = a[i] + b[it (i - 2)] - b[it (i - 1)];
	
	if (a[it (i - 3)] != a[i] + b[it (i - 2)] - b[it (i - 1)]) {
		printf ("-1");
		return 0;
	}
	
	if (a[1] == oo) {
		int i = 1;
		for (a[i] = 0; a[it (i - 3)] == oo; i = it (i - 3))
			a[it (i - 3)] = a[i] + b[it (i - 2)] - b[it (i - 1)];
		
		if (a[it (i - 3)] != a[i] + b[it (i - 2)] - b[it (i - 1)]) {
			printf ("-1");
			return 0;
		}	
	}
	
	if (a[2] == oo) {
		int i = 2;
		for (a[i] = 0; a[it (i - 3)] == oo; i = it (i - 3))
			a[it (i - 3)] = a[i] + b[it (i - 2)] - b[it (i - 1)];
		
		if (a[it (i - 3)] != a[i] + b[it (i - 2)] - b[it (i - 1)]) {
			printf ("-1");
			return 0;
		}
	}
	
	ll l = -1e9 - 2, r = 1e9 + 2;
	
	while (r - l > 1) {
		ll mid = (r + l) / 2;
		for (int i = 0; i < n; ++i)
			a[i] = oo;
		int i = 0;
		bool flag = 1;
		for (a[i] = mid; a[it (i - 3)] == oo; i = it (i - 3)) {
			a[it (i - 3)] = a[i] + b[it (i - 2)] - b[it (i - 1)];
			if (abs (a[it (i - 3)]) > 1e9) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			r = mid;
			continue;
		}
		
		/*
		if (n % 3 == 0) {
		
		}
		*/

		for (int i = 0; i < n; ++i) {
			assert (a[i] != oo);
			/*
			if (a[i] == oo)
				a[i] = 0;
			*/
		}
		for (int i = 0; i < n; ++i) {
			if (b[i] < a[it (i - 1)] + a[i] + a[it (i + 1)]) {
				flag = 0;
				break;
			}
		}
		if (!flag)
			r = mid;
		else
			l = mid;
	}
		
	if (l == -1e9 - 2 || r == 1e9 + 2) {
		printf ("-1");
		return 0;
	}

	for (int i = 0; i < n; ++i)
		a[i] = oo;

	a[0] = l;
	for (int i = 0; a[it (i - 3)] == oo; i = it (i - 3))
		a[it (i - 3)] = a[i] + b[it (i - 2)] - b[it (i - 1)];
	
	for (int i = 0; i < n; ++i) {
		if (b[i] != a[i] + a[it (i - 1)] + a[it (i + 1)]) {
			printf ("-1");
			return 0;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (abs (a[i]) > 1e9) {
			printf ("-1");
			return 0;
		}
	}
	
	for (int i = 0; i < n; ++i)
		printf ("%I64d ", a[i]);

	return 0;
}