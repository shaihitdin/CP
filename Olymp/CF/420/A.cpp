#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;

int a[N][N];
int n, m;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	m = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}	
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 1)
				continue;
			bool ok = 0;
			for (int s = 1; s <= m; ++s) {
				for (int t = 1; t <= n; ++t) {
					if (a[i][s] + a[t][j] == a[i][j]) {
						ok = 1;
					}
				}
			}
			if (!ok) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}