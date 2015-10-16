#include <bits/stdc++.h>

using namespace std;

__int8 d[21][11][11][11][11][11][1 << 5];

string ans[21];

int n, m, a[100], b[100];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= m; ++i)
		cin >> b[i];

	memset (d, -1, sizeof (d));

	d[0][a[1]][a[2]][a[3]][a[4]][a[5]][0] = 1;

	for (int i = 1; i <= m + 1; ++i) {
		for (int j1 = 0; j1 <= a[1]; ++j1)
		for (int j2 = 0; j2 <= a[2]; ++j2)
		for (int j3 = 0; j3 <= a[3]; ++j3)
		for (int j4 = 0; j4 <= a[4]; ++j4)
		for (int j5 = 0; j5 <= a[5]; ++j5)
		for (int p = 0; p < (1 << 5); ++p) {
			if (d[i - 1][j1][j2][j3][j4][j5][p] == -1)
				continue;
			for (int mask = 0; mask < (1 << 5); ++mask) {
				int cnt = 0;
				for (int j = 4; j >= 0; --j)
					if ((!bit (mask, j)) && bit (mask, j + 1))
						++cnt;
				cnt += (bit (mask, 0));
				if (cnt != b[i])
					continue;
				int newj1 = j1, newj2 = j2, newj3 = j3, newj4 = j4, newj5 = j5;
				if ((!bit (p, 0)) && bit (mask, 0))
					--newj1;
				if ((!bit (p, 1)) && bit (mask, 1))
					--newj2;
				if ((!bit (p, 2)) && bit (mask, 2))
					--newj3;
				if ((!bit (p, 3)) && bit (mask, 3))
					--newj4;
				if ((!bit (p, 4)) && bit (mask, 4))
					--newj5;
				if (newj1 < 0 || newj2 < 0 || newj3 < 0 || newj4 < 0 || newj5 < 0)
					continue;
    			d[i][newj1][newj2][newj3][newj4][newj5][mask] = p;
			}
		}
	}

	
	
	for (int j1 = 0; j1 <= a[1]; ++j1)
	for (int j2 = 0; j2 <= a[2]; ++j2)
	for (int j3 = 0; j3 <= a[3]; ++j3)
	for (int j4 = 0; j4 <= a[4]; ++j4)
	for (int j5 = 0; j5 <= a[5]; ++j5)
	for (int p = 0; p < (1 << 5); ++p) {
		if (d[m][j1][j2][j3][j4][j5][p] == -1)
			continue;
		int newj1 = j1, newj2 = j2, newj3 = j3, newj4 = j4, newj5 = j5;
		/*
		if (bit (p, 0))
			--newj1;
		if (bit (p, 1))
			--newj2;
		if (bit (p, 2))
			--newj3;
		if (bit (p, 3))
			--newj4;
		if (bit (p, 4))
			--newj5;
		cerr << newj1 << " " << newj2 << " " << newj3 << " " << newj4 << " " << newj5 << "\n";
		*/
		if (newj1 == 0 && newj2 == 0 && newj3 == 0 && newj4 == 0 && newj5 == 0) {
			int now1 = j1, now2 = j2, now3 = j3, now4 = j4, now5 = j5, mask = p;
			for (int j = m; j; --j) {
				for (int k = 0; k < m; ++k)
					if (bit (mask, k))
						ans[j] += '*';
					else
						ans[j] += '.';
				int parent = d[j][now1][now2][now3][now4][now5][mask];
				if ((!bit (parent, 0)) && bit (mask, 0))
					++newj1;
				if ((!bit (parent, 1)) && bit (mask, 1))
					++newj2;
				if ((!bit (parent, 2)) && bit (mask, 2))
					++newj3;
				if ((!bit (parent, 3)) && bit (mask, 3))
					++newj4;
				if ((!bit (parent, 4)) && bit (mask, 4))
					++newj5;
			}
			for (int j = 1; j <= m; ++j)
				cout << ans[j] << "\n";
			exit (0);
		}
	}
	
	return 0;
}