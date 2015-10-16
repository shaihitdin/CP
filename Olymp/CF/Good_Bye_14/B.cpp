#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;
const int N = 321;
int n, a[N];
bitset <N>  d[N];
char x;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	scanf ("\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf ("%c", &x);
			if (x == '1')
				d[i][j] = 1;
			else
				d[i][j] = 0;
		}
		scanf ("\n");
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if (d[i][k] == 1)
					d[i] |= d[k];
	for (int i = 1; i <= n; ++i) {
		int mn = a[i], mnpos;
		for (int j = i + 1; j <= n; ++j) {
			if (mn > a[j] && d[i][j] == 1) {
				mn = a[j];
				mnpos = j;
			}
		}
		if (mn == a[i])
			continue;
		swap (a[i], a[mnpos]);
	}
	for (int i = 1; i <= n; ++i)
		printf ("%d ", a[i]);
	return 0;
}