#include <bits/stdc++.h>

using namespace std;

int n, k, f[110][110];

int main () {

	freopen ("chess.out", "w", stdin);
	
	cin >> n >> k;

	string s, s2;

	for (int j = 1; j <= k; ++j) {
	
		cin >> s >> s2;
	
		for (int i = 1; i <= n / 2; ++i) {
			int x, y;
			cin >> x >> y;
			f[x][y] = f[y][x] = j;
		}
		
	}
	
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (f[a][b] == 0)
				continue;
			for (int c = 1; c <= n; ++c) {
				for (int d = 1; d <= n; ++d) {
					if (f[c][d] == f[a][b]) {
						if (!(f[a][c] == 0 || f[a][c] == f[b][d])) {
							cout << "BAD Sncr\n";
							return 0;
						}
					}
				}
			}
		}
	}
	
	cout << "GUT";
	return 0;
}