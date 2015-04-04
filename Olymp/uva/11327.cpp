#include <iostream>
#include <stdio.h>

using namespace std;

#ifdef _WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

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
inline long long gcd (long long a, long long b) {
	return b ? gcd (b, a % b) : a;
}
long long n, d[100001*2];
int main(){
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	d[1] = 2;
	for (int i = 2 ; i <= 200000; ++i) {
		d[i] = d[i - 1] + phi(i);
	}
	while(1) {
		scanf(I64, &n);

		if (n == 0) {
			return 0;
		}
		int i;
		for (i = 0; n - d[i] >= 1; ++i);
		
		n -= d[i - 1];
		int j;
		for (j = 0; j <= i ; ++j) {
			if ( gcd (i, j)  == 1) {
				if (n == 1) {
					printf ("%d/%d\n", j, i);
					break;
				}
				else {
					--n;
				}
			}
		}
	}
	return 0;
}