#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int t;
int a[1000001];
const int inf = 1000000009;
int main () {
	freopen ("citystar.in", "r", stdin);
	freopen ("citystar.out", "w", stdout);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		printf ("Scenario #%d:\n",test);
		int n;
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf ("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= 200; ++i) {
			for (int j = 1; j <=n; ++j) {
				for (int k = 1; k <= n; ++k)
					d[i][j][k] = -1;
			}
		}
		for (int i =
	}
	return 0;
}