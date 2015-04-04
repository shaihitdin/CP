#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1001;
const long long modulo = 1000000007;
long long n, a[5][N];
int main () {
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%I64d", &a[0][i]);
	int i = 1;
	for (;n != 1;++i, --n)
		for (int j = 2; j <= n; ++j)
			if (i & 1)
				a[i & 1][j - 1] = (a[!(i & 1)][j - 1] + a[!(i & 1)][j]) % modulo;
			else
				a[i & 1][j - 1] = (a[!(i & 1)][j - 1] * a[!(i & 1)][j]) % modulo;
	--i;
	printf ("%I64d", a[i & 1][1]);
	return 0;
}