#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll divide (const ll &n, const ll &k, const ll &mod) {
	if (k == 0)
		return 0;
	return n / k;
}

ll multiply (const ll &a, const ll &b, const ll &mod) {
	if (!a || !b)
		return 0;
	ll c = multiply (a >> 1LL, b, mod);
	return ( ( (c * 2) % mod) + ( (a & 1LL)? b: 0) ) % mod;
}

ll bin_pow (const ll &num, const ll &power, const ll &mod) {
	if (power == 0)
		return (1) % mod;
	ll b = bin_pow (num, power >> 1LL, mod);
	return multiply (multiply (b, b, mod), (power & 1LL)? num : 1, mod);
}

ll sum (const ll &first_el, const ll &q, const ll &n, const ll &mod) {
	if (q == 1)
		return (first_el * n) % mod;
	ll temp = bin_pow (q, n, mod);
	--temp;
	if (temp < 0)
		temp += mod;
	return divide (multiply (first_el, temp, mod), q - 1, mod);
}

ll n, m, num, q, modulo, x[3], y[3];

int main () {
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	scanf ("%I64d%I64d%I64d", &n, &m, &num);
	scanf ("%I64d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%I64d%I64d%I64d%I64d%I64d", &x[1], &x[2], &y[1], &y[2], &modulo);
		modulo *= (num - 1);
		ll sum1 = sum (bin_pow (num, (x[1] - 1) * m + y[1], modulo), num, y[2] - y[1] + 1, modulo);
		ll sum2 = sum (sum1, bin_pow (num, m, modulo), x[2] - x[1] + 1, modulo);
		printf ("%I64d\n", sum2);
	}
	return 0;
}