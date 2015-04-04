#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
#define mkp make_pair
int n, m, i, j;
int cnt;
int d[] = {-2, -1, 1, 2};
bool u[30][30];
int sz;
char ans[30][30][30*30];
bool rec (int a, int b) {
	u[a][b] = 1;
	++cnt;
	ans[n][m][++sz] = a + 'A' - 1;
	ans[n][m][++sz] = b + '0';
	if (cnt == n * m) {
		u[a][b] = 0;
		--cnt;
		return 1;
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (abs (d[i]) == abs(d[j]) )
				continue;
			if (a + d[i] >= 1 && a + d[i] <= n  && b + d[j] >= 1 && b + d[j] <= m) {
				if (!u[a + d[i]][b + d[j]]) {
					if (rec (a + d[i], b + d[j])) {
						--cnt;
						u[a][b] = 0;
						return 1;
					}
				}
			}
		}
	}
	--cnt;
	u[a][b] = 0;	
	sz -= 2;
	return 0;
}
int main () {
	freopen ("knight.in", "r", stdin);
	freopen ("knight.out", "w", stdout);	
	int t;
	scanf ("%d", &t);
	for(int test = 1; test <= t; ++test) {
		scanf ("%d%d", &n, &m);
		swap (n, m);
		printf("Scenario #%d:\n",test);
		rec (1, 1);
		for (int i = 1; i <= sz; i += 2) {
			printf ("%c%c",ans[n][m][i],ans[n][m][i+1]);
		}	
		if (sz == 0) {
			printf ("impossible");
		}
		printf ("\n\n");
		sz = 0;
	}
	return 0;
}