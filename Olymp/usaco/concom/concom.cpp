/*
ID: shaihit1
PROG: concom
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int x, y, z, n;
int a[101][101], g[101][101];
bool u[101][101];
int main() {
	
	freopen ("concom.in", "r", stdin);
	freopen ("concom.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> z;
		a[x][y] = g[x][y] = z;
	}
	for (int i = 1; i <= 100; ++i)
		a[i][i] = 100;
	
	for (int step = 1; step <= 100; ++step)
		for (int i = 1; i <= 100; ++i)
			for (int j = 1; j <= 100; ++j) {
				if (u[i][j] || i == j || a[i][j] <= 50)
					continue;
				u[i][j] = 1;
				for (int k = 1; k <= 100; ++k)
						a[i][k] += g[j][k];
			}
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			if (i != j && a[i][j] > 50)
				cout << i << " " << j /*<< " " << a[i][j]*/ << "\n";

	return 0;
}
