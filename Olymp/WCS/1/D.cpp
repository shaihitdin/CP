#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9, bpr = 1e9 + 7, N = 1e4 + 100;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string a[N];
string ans[N];
int cnt;
int n, m;
bool u[N];
vector <int> g[N];
int p[N];
pair <int, int> t_pos[N];

inline bool inside (int x, int y) {
	return (1 <= x && x <= n) && (1 <= y && y <= m);
}

inline bool dfs (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!p[to] || dfs (p[to])) {
			p[v] = to, p[to] = v;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = '#' + a[i];
		ans[i] = a[i];
	}
	
	int num[n + 3][m + 3];
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			num[i][j] = ++cnt, t_pos[cnt] = make_pair (i, j);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1 + (i & 1); j <= m; j += 2) {
			for (int d = 0; d < 4; ++d) {
				int ni = dx[d] + i, nj = dy[d] + j;
				if (inside (ni, nj) && a[i][j] != '*' && a[ni][nj] != '*')
					g[num[i][j]].emplace_back (num[ni][nj]);
			}
		}
	}
	
	for (int run = 1; run;) {
		run = 0;
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= cnt; ++i) {
			if (!p[i])
				dfs (i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1 + (i & 1); j <= m; j += 2) {
			if (p[num[i][j]]) {
				int px = t_pos[p[num[i][j]]].first, py = t_pos[p[num[i][j]]].second;
				//cerr << i << " " << j << ", " << px << " " << py << "\n";
				if (px == i - 1) {
					ans[px][py] = 'M';
					ans[i][j] = 'W';
				} else if (px == i + 1) {
					ans[px][py] = 'W';
					ans[i][j] = 'M';
				} else if (py == j - 1) {
					ans[px][py] = '[';
					ans[i][j] = ']';
				} else if (py == j + 1) {
					ans[px][py] = ']';
					ans[i][j] = '[';
				} else {
					assert (0);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}