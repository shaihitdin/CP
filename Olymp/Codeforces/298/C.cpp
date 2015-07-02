#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5;

ll a[N], A, n, sum;

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> A;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		sum += a[i];

	for (int i = 1; i <= n; ++i) {
		ll now = sum - a[i];
		ll l = 1, r = a[i];
		/*
		if (n == 1)
			l = A - now, r = A - now;
		*/
		r = min (r, A - (n - 1));
		l = max (l, A - now);
		cout << (l - 1) + (a[i] - r) << " ";
	}

	return 0;
}