#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll multiply (const ll &a, const ll &b, const ll &mod) {
	return (a * b) % mod;
}

ll bin_pow (const ll &num, const ll &power, const ll &mod) {
	if (!power)
		return 1;
	ll b = bin_pow (num, power >> 1LL, mod);
	return multiply (multiply (b, b, mod), (power & 1LL)? num : 1, mod);
}

ll divide (const ll &n, const ll &k, const ll &mod) {
	return (n * bin_pow(k, mod - 2, mod)) % mod;
}

ll sum (const ll &first_el, const ll &q, const ll &n, const ll &mod) {
	if (q == 1)
		return (first_el * n) % mod;
	ll temp = bin_pow (q, n, mod);
	--temp;
	if (temp < 0)
		temp += mod;
	return (divide (multiply (first_el, temp, mod), q - 1, mod)) % mod;
}

ll n, m, num, q, modulo, x[3], y[3];
int main () {
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> n >> m >> num;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> x[1] >> x[2] >> y[1] >> y[2] >> modulo;
		ll sum1 = sum (bin_pow (num, (x[1] - 1) * m + y[1], modulo), num, y[2] - y[1] + 1, modulo);
		ll sum2 = sum (sum1, bin_pow (num, m, modulo), x[2] - x[1] + 1, modulo);
		sum2 %= modulo;
		cout << sum2 << "\n";
	}
	return 0;
}