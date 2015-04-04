#include<iostream>
#include<stdio.h>
using namespace std;
long long t, b, n, rate;
int main () {
	freopen ("tricks.in", "r", stdin);
	freopen ("tricks.out", "w", stdout);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d%d", &b, &n);
		printf ("Scenario #%d:\n",test);
		long long temp = b;
		rate = 0;
		for (long long i = 2; i <= b; ++i) {
			if(temp % i == 0 && (i * i != temp)) {
				temp /= i;
				rate = max (rate, i);
			}
		}
		rate = max (temp, rate);
		int ans = 0;
		for (int i = rate, j = 1; i <= n; i *= rate, ++j) {
			ans += ((n/i)); 
			ans -= (j/rate);
		}
		printf ("%d\n\n", ans);
	}
	return 0;
}