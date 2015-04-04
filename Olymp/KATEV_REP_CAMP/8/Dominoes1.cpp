#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

vector <pair <int, int> > horizontal, vertical;

char mask[50][50];
int n, p;

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	srand (time (0));
	scanf ("%d%d", &n, &p);

	for (int i = 0; i <= n; ++i)
		mask[0][i] = 10, mask[i][0] = 10, mask[i][n + 1] = 10, mask[n + 1][i] = 10;

	for (int i = 1; i <= p; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		mask[x][y] = 10;
	}

	rec (1, 1);
	
	for (int mask = 0; mask < (1 << n)
	
	puts ("No");

	exit (0);
}