#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0};
int dy[] = {0, -1};

inline bool inside (int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j =  1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	d[1][1][1] = a[1][1];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			int nx = i - (j - 1), ny = 1 + (j - 1);
			for (int k = 1; k <= i; ++k) {
				int nx2 = i - (k - 1), ny2 = 1 + (k - 1);				
				for (int ee = 0; ee < 2; ++ee) {
					if (!inside (nx + dx[ee], ny + dy[ee]))
						continue;
					for (int ee2 = 0; ee2 < 2; ++ee2) {
						if (!inside (nx2 + dx[ee], ny2 + dy[ee]))
							continue;
						d[i
					}
				}
			}
		}
	}
	
	return 0;
}