#include <bits/stdc++.h>

using namespace std;

const int N = 505;

bitset <N> d[64][2][N];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
		
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		d[0][z][x][y] = 1;
	}

	for (int step = 1; step < 64; ++step) {
		for (int z = 0; z < 2; ++z) {
			for (int k = 1; k <= n; ++k) {
				for (int i = 1; i <= n; ++i) {
					if (d[step - 1][z][i][k])
						d[step][z][i] |= d[step - 1][z ^ 1][k];
				}
			}
		}
	}
	
	bitset <N> can;

	can[1] = 1;
	
	long long ans = 0;
	int z = 0;
	
	for (int step = 61; step >= 0; --step) {
		bitset <N> newcan;
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			if (can[i]) {
				for (int j = 1; j <= n; ++j) {
					if (d[step][z][i][j]) {
						newcan[j] = 1;
						flag = 0;
					}
				}
			}
		}
		if (!flag) {
			z ^= 1;
			ans += (1ll << step);
			can = newcan;
		}
	}
	
	if (ans > 1e18) {
		cout << -1;
		return 0;
	}
	
	cout << ans;
	
	return 0;
}