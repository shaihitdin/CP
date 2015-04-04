#include <iostream>
#include <stdio.h>
using namespace std;
int a[15], n, k, mxpos, mx;

inline int calc (const int &x) {
	int res = 0;
	for (int i = 2; i <= 8; ++i)
		a[i] = x * (i - 1);
	for (int j = n; j > -1; --j) {
	    int mx = -1, mxpos = -1;
		for (int i = 1; i <= 9; ++i) {
			if (a[i] <= j && mx < a[i]) {
				mx = a[i];
				mxpos = i;
			}
		}
		if (j - mx > 0) {
		}
		res = max (res, j - mx);
	}
	return res;
}
int main () {
	scanf ("%d%d", &k, &n);
	printf ("FILE reverse %d\n", k);
	a[9] = n;
	a[1] = 0;
	int l = 0, r = 255;
	/*
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (calc (mid) > calc (mid + 1))
			l = mid;
		else
			r = mid;
	}
	*/
	mx = 0;
	for (; l <= r; ++l)
		if (calc (l) < calc (mx))
			mx = l;
	calc (mx);
	for (int i = 1; i <= 9; ++i)
		printf ("%d ", a[i]);
	printf ("\n");	
	for (; n > -1; --n) {
		mx = -1, mxpos = -1;
		for (int i = 1; i <= 9; ++i) {
			if (a[i] <= n && mx < a[i]) {
				mx = a[i];
				mxpos = i;
			}
		}
		if (a[mxpos] == n) {
			printf ("P %d\n", mxpos);
			continue;
		}
		printf ("S %d 9\n", mxpos);
		a[9] = a[mxpos] + 1;
		while (a[9] != n) {
			printf ("S 9 9\n");
			++a[9];
		}
		printf ("P 9\n");
	}
	return 0;
}