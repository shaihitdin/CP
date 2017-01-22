#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll sum (ll a) {
	return (a * (a + 1)) / 2;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ll a, b;

	cin >> a >> b;

	cout << sum (b) - sum (a - 1);

	return 0;
}