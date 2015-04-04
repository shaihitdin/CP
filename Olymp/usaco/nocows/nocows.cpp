/*
ID: shaihit1
PROG: nocows
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int modulo = 9901;

unsigned short n, k, d[101][201][201], c[201][201], ans;

int main() {
	
	freopen ("nocows.in", "r", stdin);
	freopen ("nocows.out", "w", stdout);

	cin >> n >> k;

	d[1][1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % modulo;
	}
	
	int calc = 0;
	for (int lvl = 1; lvl < k; ++lvl)
		for (int node = 1; node <= n; ++node)
			for (int node_lvl = 1; node_lvl <= n; ++node_lvl) {
				if (!d[lvl][node][node_lvl])
					continue;
				for (int new_node = 2; (new_node >> 1) <= node_lvl && new_node + node <= n; new_node += 2) {
					calc = int (d[lvl][node][node_lvl]) * c[node_lvl][new_node >> 1];
					calc %= modulo;
					d[lvl + 1][node + new_node][new_node] += calc;
					if (d[lvl + 1][node + new_node][new_node] >= modulo)
						d[lvl + 1][node + new_node][new_node] -= modulo;
				}
			}
	for (int i = 1; i <= n; ++i)
		ans = (ans + d[k][n][i]) % modulo;
	printf ("%d\n", ans);
	return 0;
}
