#include <bits/stdc++.h>

using namespace std;

const int N = 2201, bpr = 1e9 + 9, pr = 3;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool inside (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}


int px[4], py[4];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	int ans, ans1, ans2;
	ans = 0, ans1 = 1, ans2 = 1;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			px[0] = px[1] = px[2] = px[3] = i;
			py[0] = py[1] = py[2] = py[3] = j;
			for (int
		}
	}
	
	return 0;
}