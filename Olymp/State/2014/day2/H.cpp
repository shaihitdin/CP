#include <iostream>
#include <stdio.h>
using namespace std;
int a, b, t;
int main () {
	freopen ("H.in", "r", stdin);
	freopen ("H.out", "w", stdout);
	scanf ("%d", &t);
	++t;
	while (--t) {
		scanf ("%d%d", &a, &b);
		if (a & 1)
			printf ("FIRST\n");
		else
			printf ("SECOND\n");
	}
	return 0;
}