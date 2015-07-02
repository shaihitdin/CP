#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll gcd (const ll &a, const ll &b) {
	return b ? gcd (b, a % b) : a;
}

int main () {
    /*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	int n;

	cin >> n;

	ll ans = 1;
	
	for (int i = n; i >= n / 2 + 1; --i) {
		ans = ans / gcd (ans, i) * i;
	}

	cout << ans;

	return 0;
}