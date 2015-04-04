#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e5 + 1;

long long d[N];

int n, a[N];
int q, l, r;

int main () {

	freopen ("bumblebee.in", "r", stdin);
	freopen ("bumblebee.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		d[i] = d[i - 1] + a[i];
	}
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &l, &r);
		if (d[r] - d[l - 1] == r - l + 1)
			puts ("2");
		else
			puts ("1");
	}
	return 0;
}