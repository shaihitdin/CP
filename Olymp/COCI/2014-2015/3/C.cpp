#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int height[3001], l = 3001, r, n, width, perimeter;
char a[3001][3001];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int l_temp, r_temp, h;
		scanf ("%d%d%d", &l_temp, &r_temp, &h);
		l = min (l, l_temp);
		r = max (r, r_temp);
		for (++l_temp; l_temp < r_temp; ++l_temp)
			height[l_temp] = max (height[l_temp], h);		
	}
	memset (a, '.', sizeof(a) );
	for (int i = l; i <= r; ++i) {
		width = max (width, height[i]);
	}
	for (int i = l, j = 0; i <= r; ++i, ++j) {
		for (int k = min (height[i - 1], height[i]); k <= max(height[i - 1], height[i]); ++k) {
			a[j][k] = '#';
		}
	}
	for (int i = width; i >= 1; --i) {
		for (int j = 1; j <= (r - l); ++j) {
			cerr << a[j][i];
			if(a[j][i] == '#')	++perimeter;
		}
	}
	printf ("%d\n", perimeter);
	for (int i = width; i >= 1; --i) {
		for (int j = 1; j <= (r - l); ++j) {
			printf ("%c", a[j][i]);
		}
		printf ("\n");
	}
	for (int i = 1; i <= (r - l); ++i)
		printf("*");
	return 0;
}