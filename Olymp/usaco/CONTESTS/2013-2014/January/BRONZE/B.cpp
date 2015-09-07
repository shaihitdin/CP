#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/*
	1 2 3
	4 5 6
	7 8 9
*/

const int N = 505;

short dx[] = {-1, 0, 0, 1};

short dy[] = {0, -1, 1, 0};

bool u[N][N];

int n, m, a[N][N], b[N][N], last1, last2;
int cnt, diff, temp;

inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int q[N * N * 3], stq, enq;

inline void bfs (const int &i, const int &j) {
	stq = enq = 0;
	q[enq++] = i;
	q[enq++] = j;
	while (stq < enq) {
		int x = q[stq++], y = q[stq++];
		temp += b[x][y];
		u[x][y] = 1;
		for (int k = 0; k < 4; ++k) {
			int new_i = x + dx[k], new_j = y + dy[k];
			if (inside (new_i, new_j) && !u[new_i][new_j] && abs (a[x][y] - a[new_i][new_j]) <= diff) {
				q[enq++] = new_i;
				q[enq++] = new_j;
				u[new_i][new_j] = 1;
			}
		}
	}	
}

int main () {
	freopen ("ccski.in", "r", stdin);
	freopen ("ccski.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &b[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (b[i][j] == 1) {
				last1 = i;
				last2 = j;
				++cnt;
			}
	int l = -1, r = 1e9 + 1;
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		memset (u, 0, sizeof (u));
		diff = mid;
		temp = 0;
		bfs (last1, last2);
		if (temp == cnt)
			r = mid;
		else
			l = mid;
	}
	printf ("%d", r);
	return 0;
}