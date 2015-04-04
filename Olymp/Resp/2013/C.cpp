#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
const int N = 60;
ull suff[N], ans, a[N];
int n;
int TL;
void TLE () {
	if (TL <= clock() * 1000 / CLOCKS_PER_SEC)
    	exit(1);		
}
ull gcd (const ull &a, const ull &b) {
	return b ? gcd (b, a % b) : a;
}
inline void rec (const int &el, const ull &x, const ull &y) {
	TLE();
	if (el == n) {		
		if (x == y)
			++ans;
		return;
	}		
	if (x < y)
		if ((x * suff[el]) / gcd (x, suff[el]) < y)
			return;
	else
		if ((y * suff[el]) / gcd (y, suff[el]) < x)
			return;
	rec (el + 1, (x * a[el]) / gcd (x, a[el]), y);
	rec (el + 1, x, (y * a[el]) / gcd (y, a[el]) );
}
int main (int argc, char *argv[]) {
	TL = atoi(argv[1]);
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf ("%I64d", &a[i]);
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i)
		suff[i] = ((a[i]) * suff[i + 1]) / gcd (suff[i + 1], a[i]);
	rec (1, a[0], 1);
	printf ("%I64d", ans * 2);
	return 0;
}