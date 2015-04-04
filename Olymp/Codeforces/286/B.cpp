#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
const int N = 101;
bool u[N];
int n, m;
bool e[N][N][N];
int a, b, c, q;
inline bool dfs (const int &v, const int &to, const int &edge) {
	if (u[v])
		return 0;
	u[v] = 1;
	if (v == to)
		return 1;
	for (int i = 1; i <= n; ++i)
		if (e[v][i][edge] && dfs (i, to, edge))
			return 1;
	return 0;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> c;
		e[a][b][c] = 1;
		e[b][a][c] = 1;
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> a >> b;
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (dfs (a, b, i))
				++ans;
			memset (u, 0, sizeof (u));
		}
		cout << ans << "\n";
	}
	return 0;
}