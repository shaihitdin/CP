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
vector <char> ans[30][30];
bool rec (int a, int b) {
	u[a][b] = 1;
	++cnt;
	if (cnt == n * m) {
		ans[n][m].push_back(a + 'A' - 1);
		ans[n][m].push_back(b + '0');
		return 1;
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (min (i, j) == 0 && max(i, j) == 3) {
				continue;
			}
			if (min (i, j) == 1 && max(i, j) == 2) {
				continue;
			}
			if (a + d[i] >= 1 && a + d[i] <= n  && b + d[j] >= 1 && b + d[j] <= m) {
				if (!u[a + d[i]][b + d[j]]) {
					if (rec (a + d[i], b + d[j])) {
						ans[n][m].push_back(a + 'A' - 1);
						ans[n][m].push_back(b + '0');
						return 1;
					}
				}
			}
		}
	}	
	--cnt;
	u[a][b] = 0;
	return 0;
}
int main () {
	freopen ("knight.in", "r", stdin);
	freopen ("knight.out", "w", stdout);
	for (n = 0; n <= 26; ++n) {
		for (m = 0; m <= 26; ++m) {
			printf ("%d %d : ", n, m);
			if (n * m == 0) {
				printf ("IMPOSSIBLE\n");
				continue;
			}
			if (n * m > 26) {
				printf ("IMPOSSIBLE\n");
				continue;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (rec (i, j)) {
						goto here;
					}
				}
			}
			here:;
			for (int i = 0; i < ans[n][m].size(); i += 2) {
				printf ("%c%c",ans[n][m][i],ans[n][m][i+1]);
			}
			if (ans[n][m].size() == 0) {
				printf ("IMPOSSIBLE");
			}
			printf ("\n");
		}
	}
	return 0;
}