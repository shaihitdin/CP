#include <iostream>
#include <stdio.h>
#include <time.h>  
#include <stdlib.h>

using namespace std;
typedef long long ll;

inline ll multiply (const ll &a, const ll &b, const ll &mod) {
	if (!a || !b)
		return 0;
	ll c = multiply (a >> 1, b, mod);
	c <<= 1;
	if (c >= mod)
		c -= mod;
	ll retval = c + ( (a & 1) ? b : 0);
	if (retval >= mod)
		retval -= mod;
	return retval;
}

inline ll bin_pow (ll num, ll power, const ll &mod) {
	ll res = 1;
	while (power) {
		if (power & 1) 
			res = multiply(res, num, mod);
		num = multiply(num, num, mod), power >>= 1;		
	}
	return res;
}

inline ll divide (const ll &n, const ll &k, const ll &mod) {
	return n / k;
}

inline ll sum (const ll &first_el, const ll &q, const ll &n, const ll &modulo) {
    if (q == 1) {
    	return (first_el * n) % modulo;
    }
	ll mod = modulo * (q - 1);
	if (mod == 1 || mod == 0) {
		return 0;
	}
	ll temp = bin_pow (q, n, mod);
	--temp;
	if (temp < 0)
		temp += mod;
	return divide (multiply (first_el, temp, mod), q - 1, mod) % mod;
}
ll n, m, num, query, modulo, x[3], y[3];
int main () {
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
//	ios_base :: sync_with_stdio(0);
//	cin >> n >> m >> num;
//	cin >> query;
    scanf ("%I64d%I64d%I64d%I64d", &n, &m, &num, &query);
	for (int i = 1; i <= query; ++i) {
//		cin >> x[1] >> x[2] >> y[1] >> y[2] >> modulo;
		scanf ("%I64d%I64d%I64d%I64d%I64d", &x[1], &x[2], &y[1], &y[2], &modulo);
		if (modulo == 1 || modulo == 0) {
			printf  ("0\n");
			continue;
		}
		if (num == 1) {
//			cout << ((x[2] - x[1] + 1) * (y[2] - y[1] + 1)) % modulo << "\n";
		    printf ("%I64d\n", multiply (x[2] - x[1] + 1, y[2] - y[1] + 1, modulo) );
			continue;
		}                                             
		ll sum1 = sum (bin_pow (num, ((x[1] - 1) * m + y[1]) % modulo, modulo), num, y[2] - y[1] + 1, modulo);
		ll sum2 = sum (sum1, bin_pow (num, m, modulo), x[2] - x[1] + 1, modulo);
		printf ("%I64d\n", sum2);
	//	cout << sum2 << "\n";
	}
	exit (0);
}