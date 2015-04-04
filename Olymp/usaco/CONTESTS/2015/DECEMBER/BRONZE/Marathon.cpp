#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = 100001;
int sum_d[N], n, x[N], y[N], ans;
int get_distance (const int &sx, const int &sy, const int &fx, const int &fy) {
	return abs (sx - fx) + abs (sy - fy);
}
int main () {
	freopen ("marathon.in", "r", stdin);
	freopen ("marathon.out", "w", stdout);
	scanf ("%d", &n);	
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x[i], &y[i]);
	}
	for (int i = 2; i <= n; ++i) {
		sum_d[i] = sum_d[i - 1] + get_distance (x[i - 1], y[i - 1], x[i], y[i]);
	}
	ans = sum_d[n];	
	for (int i = 2; i < n; ++i) {
		ans = min (ans, sum_d[i - 1] + (sum_d[n] - sum_d[i + 1]) + get_distance (x[i - 1], y[i - 1], x[i + 1], y[i + 1]) );
	}
	printf ("%d\n", ans);
	return 0;
}