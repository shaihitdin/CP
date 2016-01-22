#include <bits/stdc++.h>

using namespace std;

const int N = 1200;

int sx[N], sy[N], fx[N], fy[N], tsx[N], tsy[N], tfx[N], tfy[N], cnt[N], now;

int main () {

	freopen ("buttons.in", "r", stdin);
	freopen ("buttons.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> sx[i] >> sy[i] >> fx[i] >> fy[i];
		tsx[i] = min (sx[i], fx[i]);
		tsy[i] = min (sy[i], fy[i]);
		tfx[i] = max (fx[i], sx[i]);
		tfy[i] = max (sy[i], fy[i]);
		cnt[i] = i;
	}

	now = n + 1;
	
	cin >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		int right_now = -1e9, pos = -1;
		for (int j = 1; j <= n; ++j) {
			if (tsx[j] <= x && x <= tfx[j] && tsy[j] <= y && y <= tfy[j]) {
				if (right_now < cnt[j]) {
					pos = j;
					right_now = cnt[j];
				}
			}
		}
		if (pos == -1) {
			cout << 0 << "\n";
		} else {
			cout << pos << "\n";
			cnt[pos] = ++now;
		}
	}
	
	return 0;
}