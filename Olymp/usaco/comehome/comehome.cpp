/*
ID: shaihit1
PROG: comehome
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 256, inf = 1e9;
char from, to;
int dist, n;
int d[N][N];
int main() {

	freopen ("comehome.in", "r", stdin);
	freopen ("comehome.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			d[i][j] = inf;
	for (int i = 1; i <= n; ++i) {
		cin >> from >> to >> dist;
		d[from][to] = min (d[from][to], dist);
		d[to][from] = min (d[to][from], dist);
	}
	for (int i = 1; i < 256; ++i)
		d[i][i] = 0;
	for (int k = 1; k < N; ++k)
		for (int i = 1; i < N; ++i)
			for (int j = 1; j < N; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
	int anspos = 0;
	for (int i = 'A'; i <= 'Y'; ++i) {
		if (d[i]['Z'] < d[anspos]['Z']) {
			anspos = i;
		}
	}
	printf ("%c %d\n", char (anspos), d[anspos]['Z']);
	return 0;
}
