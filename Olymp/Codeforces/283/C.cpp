#include <iostream>
#include <stdio.h>
using namespace std;
int bigger[1001];
char s[1001][1001];
int n, m, ans;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d\n", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf ("%c", &s[i][j]);
	    }
	    scanf ("\n");
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 2; i <= n; ++i) {
			if (s[i][j] < s[i - 1][j] && !bigger[i]) {
				for (int k = 2; k <= n; ++k) {
					if (bigger[k] == j) {
						bigger[k] = 0;						
					}
				}
				++ans;
				break;
			}
			if (s[i][j] > s[i - 1][j] && !bigger[i]) {
				bigger[i] = j;			
			}
		}
	}
	printf ("%d", ans);
	return 0;
}