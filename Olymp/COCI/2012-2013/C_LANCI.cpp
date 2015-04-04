#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 500001;
bool u[N];
int a[N], left, n, ans;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	int j = n, i = 1;
	for (;i < j;) {
		int use = min (j - i, a[i]);
		ans += use; 
		if (use == a[i])
			++i;
		while (i < j && use != 0) {
			--j;
			--use;
		}
	}
	printf ("%d", ans);
	return 0;
}