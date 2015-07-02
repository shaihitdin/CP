#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

double sum[N][N], prob[N][N];

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	*/
	
	int t;

	scanf ("%d", &t);

	for (int test_no = 1; test_no <= t; ++test_no) {
		int n;
		scanf ("%d", &n);
		memset (sum, 0, sizeof (sum));
		memset (prob, 0, sizeof (prob));
		prob[1][1] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				int a, b;
				scanf ("%d%d", &a, &b);
				if (a == b) {
					prob[i + 1][j] += (0.5 * prob[i][j]);
					prob[i + 1][j + 1] += (0.5 * prob[i][j]);
					sum[i + 1][j] += sum[i][j] * 0.5 + prob[i][j] * 0.5 * a;
					sum[i + 1][j + 1] += sum[i][j] * 0.5 + prob[i][j] * 0.5 * a;
				} else {
					if (a < b) {
						prob[i + 1][j] += prob[i][j];
						sum[i + 1][j] += sum[i][j] + prob[i][j] * a;
					} else {
						prob[i + 1][j + 1] += prob[i][j];
						sum[i + 1][j + 1] += sum[i][j] + prob[i][j] * b;
					}
				}
			}
		}

		double ans = 0;
		for (int j = 1; j <= n + 1; ++j)
			ans += sum[n + 1][j];
		printf ("%.6lf\n", ans);
	}
	
	return 0;
}