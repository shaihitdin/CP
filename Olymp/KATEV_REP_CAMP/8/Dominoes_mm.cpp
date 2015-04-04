#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

const int N = 51;

#define mkp make_pair
#define F first
#define S second

vector <int> g[N * N];
int n, dea;
bool u[N * N];
int p[N * N];
pair <int, int> gi[N * N];
int mask[N][N];
int ans;
vector <int> horizontal, vertical;

inline bool dfs (const int &v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!p[g[v][i]] || dfs (p[g[v][i]])) {
			p[g[v][i]] = v;
			return 1;
		}
	}
	return 0;
}


int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &dea);

	for (int i = 0; i <= n; ++i)
		mask[0][i] = 10, mask[i][0] = 10, mask[i][n + 1] = 10, mask[n + 1][i] = 10;

	for (int i = 1; i <= dea; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		mask[x][y] = 10;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			gi[(i - 1) * n + j] = mkp (i, j);
			if (((i & 1) + (j & 1)) & 1)
				continue;
			if (mask[i][j])
				continue;
			for (int k = 0; k < 4; ++k) {
				if (!mask[i + dx[k]][j + dy[k]])
					g[(i - 1) * n + j].push_back (((i - 1 + dx[k]) * n + j + dy[k]));
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (((i & 1) + (j & 1)) & 1)
				continue;
			int to_one = (i - 1) * n + j;
			if (mask[gi[to_one].F][gi[to_one].S])
				continue;
			memset (u, 0, sizeof (u));
			ans += dfs (to_one);
		}
	}

	cerr << ans;
	if (ans * 2 != (n * n - dea)) {
		puts ("No");
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!(((i & 1) + (j & 1)) & 1))
				continue;
			if (mask[i][j])
				continue;
			int k = (i - 1) * n + j;
			
			if (abs (j - gi[p[k]].S) == 1) {
				if (j < gi[p[k]].S)
					vertical.push_back (k);
				else
					vertical.push_back (p[k]);
			}
			if (abs (i - gi[p[k]].F) == 1) {
				if (i < gi[p[k]].F)
					horizontal.push_back (k);
				else
					horizontal.push_back (p[k]);
			}
		}
	}

	puts ("Yes");

	cout << horizontal.size() << "\n";

	for (int i = 0; i < horizontal.size(); ++i) {
		cout << gi[horizontal[i]].F << " " << gi[horizontal[i]].S << "\n";
	}		

	cout << vertical.size() << "\n";

	for (int i = 0; i < vertical.size(); ++i) {
		cout << gi[vertical[i]].F << " " << gi[vertical[i]].S << "\n";
	}


	return 0;
}