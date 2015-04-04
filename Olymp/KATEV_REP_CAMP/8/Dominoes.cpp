#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define F first
#define S second

vector <pair <int, int> > horizontal, vertical;

char mask[50][50];
int n, p;

const int limit = 3e7;

int cnt;

inline void rec (const char &x, const char &y) {
	if (++cnt > limit) {
		puts ("No");
		exit (0);
	}
	if (x == n && y == n + 1) {		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (mask[i][j] == 1) {
					horizontal.push_back (mkp (i, j));
				}
				if (mask[i][j] == 2) {
					vertical.push_back (mkp (i, j));
				}
			}
		}
		puts ("Yes");
		printf ("%d\n", vertical.size());
		for (int i = 0; i < vertical.size(); ++i) {
			printf ("%d %d\n", vertical[i].F, vertical[i].S);
		}
		printf ("%d\n", horizontal.size());
		for (int i = 0; i < horizontal.size(); ++i) {
		    printf ("%d %d\n", horizontal[i].F, horizontal[i].S);
		}
		exit (0);	
	}
	
	if (y == n + 1) {
		rec (x + 1, 1);
		return;
	}

	if (mask[x][y] != 0) {
		rec (x, y + 1);
		return;
	}

	if (mask[x][y] == 0 && mask[x + 1][y] == 0 && mask[x][y + 1] == 0 && mask[x + 1][y + 1] == 0) {
		mask[x + 1][y] = 1;
		mask[x][y + 1] = 1;
		rec (x, y + 1);
		mask[x + 1][y] = 1;
		mask[x][y + 1] = 1;

	}

	if (rand() & 1) {
		if (!mask[x][y + 1]) {
			mask[x][y] = 1;
			mask[x][y + 1] = 3;
			rec (x, y + 1);	
			mask[x][y] = 0;
			mask[x][y + 1] = 0;
		}
		if (!mask[x + 1][y]) {
			mask[x][y] = 2;
			mask[x + 1][y] = 4;
			rec (x, y + 1);	
			mask[x][y] = 0;
			mask[x + 1][y] = 0;
		}
	}
	else {
		if (!mask[x + 1][y]) {
			mask[x][y] = 2;
			mask[x + 1][y] = 4;
			rec (x, y + 1);	
			mask[x][y] = 0;
			mask[x + 1][y] = 0;
		}
		if (!mask[x][y + 1]) {
			mask[x][y] = 1;
			mask[x][y + 1] = 3;
			rec (x, y + 1);	
			mask[x][y] = 0;
			mask[x][y + 1] = 0;
		}				
	}
	return;
}


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
	
	
	puts ("No");

	exit (0);
}