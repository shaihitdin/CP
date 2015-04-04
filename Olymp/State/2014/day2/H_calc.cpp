#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;
// WIN = 1 DEFEAT = 2
const int N = 501;
int u[N][N][5];
inline int op (int x) {
	if (x == 1)
		return 2;
	return 1;
}
inline int lazy_dp(int x, int y, int man) {
	if (u[x][y][man] != 0)
		return u[x][y][man];
	if (x != 0 && y != 0)
		if (lazy_dp (x, y - 1, op (man) ) == man)
			u[x][y][man] = man;
	if (x > 1)
		if (lazy_dp (x - 2, y + 1, op (man) ) == man)
			u[x][y][man] = man;
	if (y > 1) 
		if (lazy_dp (x, y - 1, op (man) ) == man) 
			u[x][y][man] = man;
	if (u[x][y][man] == 0)
		u[x][y][man] = op (man);
	return u[x][y][man];
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	u[1][0][2] = 1;
	u[1][0][1] = 1;
	u[0][1][1] = 2;
	u[0][1][2] = 2;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (i == 0 && j == 0)
				continue;
			if (i & 1)
				assert (lazy_dp(i, j, 1) == 1);
			else 
				assert (lazy_dp(i, j, 1) == 2);
		}
	}
	return 0;
}