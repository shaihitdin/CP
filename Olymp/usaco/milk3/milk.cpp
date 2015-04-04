/*
ID: shaihit1
PROG: milk3
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 25, inf = 1000000000;

bool ans[N];
bool u[N][N][N];
int a, b, c;

inline void dfs (const int &x, const int &y, const int &z) {
	if (u[x][y][z])
		return;
	u[x][y][z] = 1;
	if (!x)
		ans[z] = 1;
	dfs (x - min (x, b - y), y + min (x, b - y), z);
	dfs (x - min (x, c - z), y, z + min (x, c - z));
	dfs (x + min (y, a - x), y - min (y, a - x), z);
	dfs (x, y - min (y, c - z), z + min (y, c - z));
	dfs (x + min (z, a - x), y, z - min (z, a - x));
	dfs (x, y + min (z, b - y), z - min (z, b - y));
}

int main() {
    
    freopen ("milk3.in", "r", stdin);
    freopen ("milk3.out", "w", stdout);
	
	cin >> a >> b >> c;
	
	dfs (0, 0, c);
	
	int ir = N - 1;
	while (ir && !ans[ir])	--ir;
	for (int it = 0; it < ir; ++it)
		if (ans[it])
			cout << it << " ";
	if (ans[ir])
		cout << ir;
	cout << "\n";
	return 0;
}