#include <iostream>
#include <string.h>

#include <stdio.h>
using namespace std;
const int N = 10001;
int t, n, a[N];
bool correct[N];
char u[N];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);		
		int ans = -1;		
		for (int i = 1; i <= n; ++i) {
			memset (u, 0, sizeof(u));
			u[a[1]] = 1;
			int possible = 1;
			for (int j = 2; j <= n; ++j) {
				int pos = (j > i)? j : j - 1;
				if (possible == 0) {
					if (a[j] != pos) {
						possible = 2;
						break;
					}
				}
				else {
					if (!u[pos] && a[j] != pos) {
						possible = 2;
						break;
					}
					u[a[j]] = 1;
					if (a[j] == i)
						possible = 0;
				}
			}
			if (possible != 2) {
				if (ans == -1)
					ans = i;
				else
					ans = -2;			
			}
		}
		if (ans == -1 || ans == -2)
			printf ("0\n");
		else
			printf ("%d\n", ans);
	}
	return 0;
}