#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int t;
int a[1000001];
int main () {
	freopen ("citystar.in", "r", stdin);
	freopen ("citystar.out", "w", stdout);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		printf ("Scenario #%d:\n",test);
		int n;
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);
		sort (a + 1, a + n + 1);
		int ans = 1000000001, pos;
		for (int i = 5; i <= n; ++i) {
			if (ans > a[i] - a[i - 4] + 1) {
				ans = a[i] - a[i - 4] + 1;
				pos =  i;
			}
		}
		printf ("%d: ",ans);
		for (int i = pos - 4; i <= pos; ++i) {
			printf ("%d ", a[i]);
		}
		printf("\n\n");
	}
	return 0;
}