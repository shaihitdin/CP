#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool g[N][N];

int d[3][N][N];

#define debug(x) cerr << "(" << #x << " == " << x << ") ";

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	freopen ("err", "w", stderr);
	#endif

	int n, m;
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	for (int i = 1; i <= 2; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 1; k <= n; ++k)
				d[i][j][k] = -2;

	
	for (int i = 0; i < n; ++i)
		d[1][i][1] = d[2][i][1] = -1;

	for (int len = 1; len <= n; ++len) {
		for (int i = 1; i <= 2; ++i) {
			for (int l = 0; l < n; ++l) {
				int r = (l + len - 1) % n;
				if (d[i][l][len] == -2)
					continue;
				debug (i);
				debug (l);
				debug (r);
				debug (d[i][l][len]);
				cerr << "\n";
				int l1 = (l - 1 + n) % n, r1 = (r + 1 + n) % n;
				if (i == 1) {
					if (g[l][l1] == 1)
						d[1][l1][len + 1] = 1;
					if (g[l][r1] == 1)
						d[2][l][len + 1] = 3;
				} else {
					if (g[r][r1] == 1)
						d[2][l][len + 1] = 2;
					if (g[r][l1] == 1)
						d[1][l1][len + 1] = 4;
				}
			}
		}
	}
	
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cerr << g[i][j] << " ";
		}
		cerr << "\n";
	}	
	
	cerr << "\n";
	*/
	int st_l = -1, st_r = -1, st_end = -1;

	for (int j = 1; j <= 2; ++j)
		for (int i = 0; i < n; ++i)
			if (d[j][i][n] != -2)
				st_l = i, st_end = j;
	
	
	if (st_l == -1) {
		cout << -1;
		return 0;
	}

	vector <int> ans;
	
	st_r = n;
	
    ans.push_back (st_l);

	for (st_r = n; st_r > 1; --st_r) {
		if (d[st_end][st_l][st_r] == 1) {
			ans.push_back (st_l);
			++st_l;
			st_l %= n;
			st_end = 1;
		} else if (d[st_end][st_l][st_r] == 2) {
			ans.push_back ((st_l + st_r - 1) % n);
			st_end = 2;
		} else if (d[st_end][st_l][st_r] == 3) {
			ans.push_back ((st_l + st_r - 1) % n);
			st_end = 2;
		} else if (d[st_end][st_l][st_r] == 4) {
			ans.push_back (st_l);
			++st_l;
			st_l %= n;
			st_end = 1;
		} else {
			assert (0);
		}
	}

    
    
    for (auto it : ans) {
    	cout << it + 1 << "\n";
    }
    
    return 0;
}
