#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

int d[N][6];
int n, m;
string s;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);


	d[0][3] = 1;

	ios_base :: sync_with_stdio (0);
	cin >> n;
	cin >> m;
	cin >> s;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]);
			if (j > 3 && i > 2) {
				d[i][j] -= d[i - 3][j - 3];
			}
			if (j < 3 && i > 2) {
				d[i][j] -= d[i - 3][j + 3];
			}
			d[i][j] %= m;
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	int ans = 0;
	int j = n - 1;
	cerr << "\n";
	for (int i = 0; j > 0; ++i, --j) {
		if (s[i] == 'L') {
		} else {
			for (int k = 2; k <= 5; ++k) {
				if (k + 2 <= 5 && j > 2) {
					ans = (ans + d[j][k] - d[j - 2][k + 2] ) % m;
				}
				else {
					ans = (ans + d[j][k]) % m;
				}
				cerr << ans << " ";
			}
		}
		cerr << "\n";
	}
	ans = (ans + 1) % m;
	cout << ans;
	return 0;
}