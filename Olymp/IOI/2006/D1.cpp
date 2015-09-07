#include <bits/stdc++.h>

using namespace std;

const int N = 1300;

int n;
int d[3][N][N];
bool g[N][N];

/*
			int r = (l + len - 1) % n;
			int l1 = (l - 1 + n) % n, r1 = (r + 1) % n;
			if (d[1][l][r] != -1) {
				if (g[l][l1] == 1)
					d[1][l1][r] = 1;
				if (g[l][r1] == 1)
					d[2][l][r1] = 2;
			}
			if (d[2][l][r] != -1) {
				if (g[r][r1] == 1)
					d[2][l][r1] = 3;
				if (g[r][l1] == 1)
					d[1][l1][r] = 4;
			}

*/


inline vector <int> get_ans (int st1, int end1, int l_v1) {
	vector <int> ans;
	while (st1 != end1) {
		int n_st1 = (st1 + 1) % n, n_end1 = (end1 - 1 + n) % n;
		if (d[l_v1][st1][end1] == 1) {
			ans.push_back (st1);
			st1 = n_st1;
			end1 = end1;
			l_v1 = 1;
		} else if (d[l_v1][st1][end1] == 2) {
			ans.push_back (end1);
			st1 = st1;
			end1 = n_end1;
			l_v1 = 1;
		} else if (d[l_v1][st1][end1] == 3) {
			ans.push_back (end1);
			st1 = st1;
			end1 = n_end1;
			l_v1 = 2;
		} else if (d[l_v1][st1][end1] == 4) {
			ans.push_back (st1);
			st1 = n_st1;
			end1 = end1;
			l_v1 = 2;
		} else {
			assert (0);
		}
	}

	ans.push_back (st1);
	
	reverse (ans.begin (), ans.end ());
	return ans;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int m;

	cin >> n >> m;
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x][y] = 1, g[y][x] = 1;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			d[1][i][j] = d[2][i][j] = -1;
	
		for (int i = 0; i < n; ++i)
			d[1][i][i] = d[2][i][i] = 0;
	
	for (int len = 1; len <= n / 2 + 1; ++len) {
		for (int l = 0; l < n; ++l) {
			int r = (l + len - 1) % n;
			int l1 = (l - 1 + n) % n, r1 = (r + 1) % n;
			if (d[1][l][r] != -1) {
				if (g[l][l1] == 1)
					d[1][l1][r] = 1;
				if (g[l][r1] == 1)
					d[2][l][r1] = 2;
			}
			if (d[2][l][r] != -1) {
				if (g[r][r1] == 1)
					d[2][l][r1] = 3;
				if (g[r][l1] == 1)
					d[1][l1][r] = 4;
			}
		}
	}
	
	int st1 = -1, end1 = -1, l_v1 = -1, st2 = -1, end2 = -1, l_v2 = -1;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (d[2][i][j] != -1 && d[1][j][(i - 1 + n) % n] != -1) {
				st1 = i;
				end1 = j;
				l_v1 = 2;
				st2 = j;
				end2 = (i - 1 + n) % n;
				l_v2 = 1;
			}
		}
	}
	
	if (st1 == -1) {
		cout << "-1";
		return 0;
	}
	
	//cerr << st1 + 1 << " " << end1 + 1 << " " << st2 + 1 << " " << end2 + 1;
	
	vector <int> ans1, ans2;
	
	int d_t = st2;
	
	ans1 = get_ans (st1, end1, l_v1);
	ans2 = get_ans (st2, end2, l_v2);

	for (int i = 0; i < ans1.size (); ++i)
		cout << ans1[i] + 1 << "\n";

	reverse (ans2.begin (), ans2.end ());
	
	for (int i = 1; i < ans2.size (); ++i)
		cout << ans2[i] + 1 << "\n";

	return 0;
}