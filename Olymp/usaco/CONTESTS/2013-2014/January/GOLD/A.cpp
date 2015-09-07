#include <iostream>
#include <stdio.h>

using namespace std;
const int N = 1005, inf = 1e9;

int a[N][N], x, y;
char q;


long long d[N][N];

int last[N];
int st[N * 2], sz;
int main () {
	
	freopen ("cowrect.in", "r", stdin);
	freopen ("cowrect.out", "w", stdout);

	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d %c", &x, &y, &q);
		++x, ++y;
		a[x][y] = (q == 'H') ? 1 : (-inf);
	}
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
	for (int i = 0; i < N; ++i)
		last_h[i] = N, last[i] = 0;
	/* last_h = last 'H' dog in this vertical line, last = last 'G' dog in this vertical line.*/
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (a[i][j] == -inf) {
				last[j] = i;
				last_h[j] = N;
			}
			else if (last_h[j] == N && a[i][j] == 1)
				last_h[j] = i;
		}
		
		sz = 0;
		for (int j = 1; j < N; ++j) {
			while (sz && (last[last_h[j]))
				--sz;
		}
		
		sz = 0;
		st[sz++] = 0;
		for (int j = N - 1; j; --j) {
		
		}

	}
	return 0;
}