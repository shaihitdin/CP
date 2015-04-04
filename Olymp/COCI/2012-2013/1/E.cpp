#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int magic = 42;
ll d[magic + 1];
ll now;
ll gcd (const ll &a, const ll &b) {
	return b? gcd (b, a % b) : a;
}
ll calc (const ll &n) {
	ll res = 0, now = 1, nw;
	for (ll i = 2; i <= magic; ++i, now = nw) {
		nw = (now * i) / gcd (now, i);
		res += (( (nw / now) - 1) * (n / nw) * (d[i] + 1));
		res += (((n % nw) / now) * (d[i] + 1));
	}
	return res;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	ll a, b;
	cin >> a >> b;
	d[2] = 1;
	for (int i = 3; i <= magic; ++i) {
		for (int j = 2; j <= magic; ++j) {
			if (i % j != 0) {
				d[i] = d[j] + 1;
				break;
			}
		}
	}
	cout << calc (b) - calc (a - 1);
	return 0;
}