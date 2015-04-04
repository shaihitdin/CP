/*
ID: shaihit1
PROG: ttwo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define fpos farmerpos

int n = 10;
int cpos[3], fpos[3], direction[2];
bool u[11][11][4][11][11][4];
char a[11][11];
int cnt;

int dx[] = {-1, 0, +1, 0}, dy[] = {0, +1, 0, -1};

inline bool can (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= n && (a[x][y] != '*');
}

int main() {
	
	freopen ("ttwo.in", "r", stdin);
	freopen ("ttwo.out", "w", stdout);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				fpos[1] = i;
				fpos[2] = j;
				direction[1] = 0;
			}
			else if (a[i][j] == 'C') {
				cpos[1] = i;
				cpos[2] = j;
				direction[2] = 0;
			}
		}
	}

	while (++cnt) {
		if (fpos[1] == cpos[1] && fpos[2] == cpos[2])
			break;
		if (u[fpos[1]][fpos[2]][direction[0]][cpos[1]][cpos[2]][direction[1]]) {
			puts ("0");
			exit (0);	
		}
		u[fpos[1]][fpos[2]][direction[0]][cpos[1]][cpos[2]][direction[1]] = 1;
		if (can (fpos[1] + dx[direction[0]], fpos[2] + dy[direction[0]]))
			fpos[1] += dx[direction[0]], fpos[2] += dy[direction[0]];
		else
			direction[0] = (direction[0] + 1) % 4;
		if (can (cpos[1] + dx[direction[1]], cpos[2] + dy[direction[1]]))
			cpos[1] += dx[direction[1]], cpos[2] += dy[direction[1]];
		else
			direction[1] = (direction[1] + 1) % 4;
	}
	--cnt;
	printf ("%d\n", cnt);
	return 0;
}
