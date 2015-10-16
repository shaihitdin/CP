#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

long long d[N];

inline long long phi (long long n) {
	long long ans = n;
	for (long long i = 2; i * i <= n; ++i) {
		if ((n % i) == 0) {
			while ((n % i) == 0)
				n /= i;
			ans -= ans / i;
		}
	}
	if (n > 1) ans -= ans / n;
	return ans;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	for (int i = 1; i < N; ++i) {
		d[i] = i - phi (i);
		d[i] += d[i - 1];
	}

	int t;
	
	cin >> t;

	for (int test_num = 1; test_num <= t; ++test_num) {
		int x;
		cin >> x;
		cout << "Case " << test_num << ": " << d[x] << "\n";
	}
	
	return 0;
}