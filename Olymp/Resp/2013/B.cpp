#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, cnt;
int a[1001][1001];
int main () {
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 0)
				++cnt;
	if (cnt == 0) {
		printf ("%d", n * m);	
		return 0;
	}
	if (cnt == n * m) {
		cnt = 0;
	}
	printf ("%d", cnt);	
	return 0;
}