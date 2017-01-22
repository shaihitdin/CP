#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1100;

int add[N][N];

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int q;

	cin >> q;

	for (int i = 1; i <= q; ++i) {
		int sx, sy, fx, fy, ke;
		cin >> sy >> sx >> fy >> fx >> ke;
		for (int i = sy; i <= fy; ++i) {
			add[i][sx] += ke;
			add[i][fx + 1] -= ke;
		}
	}

	int n, m;

	cin >> m >> n;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			add[i][j] += x;
			add[i][j + 1] -= x;
		}
	}
	
	int now = 0;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			now += add[i][j];
			if (j != n + 1)
				cout << now << " ";
		}
		cout << "\n";
	}
	
	return 0;
}