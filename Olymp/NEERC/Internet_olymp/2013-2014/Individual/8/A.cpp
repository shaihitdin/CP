#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 1;
int n, m, a[N], b[N], diff, temp_sum;
int main () {
	freopen ("xpart.in", "r", stdin);
	freopen ("xpart.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; ++i)
		scanf ("%d", &b[i]);
	int i = 1, j = 1;
	for (; j <= m; ++j) {
		temp_sum = 0;
		while (i <= n && temp_sum < b[j]) {
			temp_sum += a[i];
			++i;
		}
		if (temp_sum < b[j]) {
			printf ("-1");
			return 0;
		}
	}
	for (int i = 1; i <= m; ++i)
		diff -= b[i];
	for (int i = 1; i <= n; ++i)
		diff += a[i];

	printf ("%d", diff);
	return 0;
}