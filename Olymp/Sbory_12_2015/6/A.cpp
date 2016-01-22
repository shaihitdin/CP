#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;

int u[N][N];
int calc[N][N];
char a[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
char nxt[256];
int ans;

inline bool inside (int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}


inline int dfs (int i, int j) {
	if (u[i][j] == 2) {
		cout << "Poor Inna!";
		exit (0);
	}
	if (u[i][j] == 1)
		return calc[i][j];
	u[i][j] = 2;
	calc[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int nx = i + dx[k], ny = j + dy[k];
		if (!inside (nx, ny) || nxt[a[i][j]] != a[nx][ny])
			continue;
		dfs (nx, ny);
		calc[i][j] = max (calc[i][j], 1 + calc[nx][ny]);
	}

	u[i][j] = 1;

	return calc[i][j];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	
	nxt['D'] = 'I';
	nxt['I'] = 'M';
	nxt['M'] = 'A';
	nxt['A'] = 'D';
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!u[i][j] && a[i][j] == 'D')
				ans = max (ans, dfs (i, j));
		}
	}
	if (ans <= 3) {
		cout << "Poor Dima!";
	} else {
		cout << ans / 4;
	}
	
	return 0;
}