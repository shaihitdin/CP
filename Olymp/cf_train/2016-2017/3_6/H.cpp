#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, k;
int up[32][N];
int x[N], y[N], to[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		to[x[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		up[0][i] = to[y[i]];
	}
	
	for (int i = 1; i < 32; ++i) {
		for (int j = 1; j <= n; ++j) {
			up[i][j] = up[i - 1][up[i - 1][j]];
		}
	}
	
	while (k--) {
		int ps, x;
		cin >> ps >> x;
		for (int i = 0; i < 32; ++i)
			if (x & (1 << i))
				ps = up[i][ps];
		cout << ps << "\n";
	}
	
	return 0;
}