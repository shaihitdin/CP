#include <bits/stdc++.h>

using namespace std;

const int N = 3001, enemy = 2, mate = 1;

char g[N][N];

int cmp[N];
int col[N];
bool u_c[N];

vector <int> cmp_l[N];


inline void can_go (const int &v, const int &cmp_num) {
	cmp[v] = cmp_num;
	cmp_l[cmp_num].push_back (v);
	u[v] = 1;
	for (int i = 1; i <= n; ++i)
		if (g[v][i])
			can_go (i, cmp_num);
}

inline void dfs (const int &v, const int &color) {
	col[v] = color;
	u[v] = 1;
	for (int i = 1; i <= n; ++i) {
		if (g[v][i] == enemy && col[v] == col[i])
			return;
		if (g[v][i] == mate && col[v] ^ 1 == col[i])
			return;
		if (!u[i] && g[v][i]) {
			if (g[v][i] == mate)
				dfs (i, color);
			else if (g[v][i] == enemy)
				dfs (i, color ^ 1);
		}
	}
} 


int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	
	while (t--) {

		memset (g, 0, sizeof (g));
		
		cin >> n >> m;

		for (int i = 1; i <= n; ++i)
			cmp_l[i].resize (0);
		
		for (int i = 1; i <= n; ++i)
			cin >> known[i];

		for (int i = 1; i <= m; ++i) {
			int x, y, dd;
			cin >> x >> y >> dd;
			++dd;
			g[x][y] = dd;
			g[y][x] = dd;
		}

		
		int cmp_cnt = 0;
		memset (u, 0, sizeof (u));
		for (int i = 1; i <= n; ++i)
			if (!u[i])
				can_go (i, ++cmp_cnt);

		memset (u, 0, sizeof (u));

		for (int i = 1; i <= n; ++i)
			if (!u[i])
				dfs (i, 2);
				
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] == mate && col[i] ^ 1 == col[j]) {
					cout << "NO\n";
					goto end;
				}
				if (g[i][j] == enemy && col[i] == col[j]) {
					cout << "NO\n";
					goto end;
				}
			}
		}

		int init_state1 = 0;
		
		memset (u_c, 0, sizeof (u_c));
		
		for (int i = 1; i <= n; ++i) {
			if (known[i]) {
				for (auto j : cmp_l[cmp[i]]) {
					if (col[j] == col[i]) {
						if (known[j] && known[i] != known[j]) {
							cout << "NO\n";
							goto end;
						}
					} else {
						if (known[j] && known[j] == known[i]) {
							cout << "NO\n";
							goto end;
						}
					}
					if (known[i] == 1) {
						if (col[i] == col[j])
							++init_state1;
					} else {
						if (col[i] != col[j])
							++init_state1;
					}
				}
				u_c[cmp[i]] = 1;
			}
		}
		
		
		memset (d, 0, sizeof (d));

		d[1][init_state1] = 1;
		
		for (int i = 1; i <= n; ++i) {
			u_c[cmp[i]] = 1;
			int sz1 = 0, sz2 = 0;
			for (int j = 1; j <= n; ++j) {
				if (cmp[j] == cmp[i]) {
					if (col[i] == 2)
						++sz1;
					else
						++sz2;
				}
			}
			for (int j = n; j; --j) {
				if (!d[j])
					continue;
				d[j] = 0;
				d[j + sz1] = 1;
				d[j + sz2] = 1;
			}
		}

		end:;
	}
	return 0;
}