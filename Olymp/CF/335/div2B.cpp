#include <bits/stdc++.h>

using namespace std;

const int N = 600;

bool u[N][N];
int n, m, sx, sy;
string s;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m >> sx >> sy;

	cin >> s;

	memset (u, 1, sizeof (u));

	for (int i = 0; i < s.size (); ++i) {
		cout << u[sx][sy] << " ";
		u[sx][sy] = 0;
		if (s[i] == 'U')
			--sx;
		else if (s[i] == 'D')
			++sx;
		else if (s[i] == 'L')
			--sy;
		else
			++sy;
		sx = max (1, sx);
		sx = min (n, sx);
		sy = max (1, sy);
		sy = min (m, sy);
	}

	int ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans += u[i][j];
		}
	}
	
	cout << ans;
	
	return 0;
}