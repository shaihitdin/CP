#include <iostream>
#include <stdio.h>
using namespace std;
int n,i;
int main() {
	freopen ("beautifulgraph.in", "r", stdin);
	freopen ("beautifulgraph.out", "w", stdout);
	scanf ("%d", &n);
	if (n == 1) {
		printf ("1 0");
		return 0;
	}
	if (n == 2) {
		printf ("2 1\n1 2");
		return 0;
	}
	printf("%d %d\n", n, n);
	for (i = 1; i < n; ++i) {
		printf ("%d %d\n", i, i+1);
	}
	printf ("%d 1", n);
	return 0;
}