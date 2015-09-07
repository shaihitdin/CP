#include <bits/stdc++.h>

using namespace std;


const int N = 700;
int n, m;
short a[N][N], b[N][N];
int cnt[N][N];

inline void rebuild () {
	if (m == 3) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)
					continue;
				if (b[1][2] && !a[i][j])
					continue;
				for (int k = 1; k <= n; ++k) {
					if (i == k || j == k)
						continue;
					if (b[1][3] && !a[i][k])
						continue;
					if (b[2][3] && !a[j][k])
						continue;
					if (b[1][2])
						++cnt[i][j];
					if (b[1][3])
						++cnt[i][k];
					if (b[2][3])
						++cnt[j][k];
				}
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)
					continue;
				if (b[1][2] && !a[i][j])
					continue;
				for (int k = 1; k <= n; ++k) {
					if (i == k || j == k)
						continue;
					if (b[1][3] && !a[i][k])
						continue;
					if (b[2][3] && !a[j][k])
						continue;
					for (int l = 1; l <= n; ++l) {
						if (i == l || j == l || k == l)
							continue;
						if (b[1][4] && !a[i][l])
								continue;
						if (b[2][4] && !a[j][l])
							continue;
						if (b[3][4] && !a[k][l])
							continue;
						if (b[1][2])
							++cnt[i][j];
						if (b[1][3])
							++cnt[i][k];
						if (b[1][4])
							++cnt[i][l];
						if (b[2][3])
							++cnt[j][k];
						if (b[2][4])
							++cnt[j][l];
						if (b[3][4])
							++cnt[k][l];
					}
				}
			}
		}
	}
}


int main () {
	
	for (int test = 11; test <= 11; ++test) {
		char test_n[20];
		memset (test_n, 0, sizeof (test_n));
		sprintf (test_n, "%02d", test);
		freopen (test_n, "r", stdin);
		test_n[2] = '.';
		test_n[3] = 'o';
		test_n[4] = 'u';
		test_n[5] = 't';
		freopen (test_n, "w", stdout);

		
		cin >> m >> n;


		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> b[i][j];
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> a[i][j];

		while (1) {
			memset (cnt, 0, sizeof (cnt));
		    rebuild ();
			int mxi = 0, mxj = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (cnt[mxi][mxj] + cnt[mxj][mxi] < cnt[i][j] + cnt[j][i])
						mxi = i, mxj = j;
			
			a[mxi][mxj] = a[mxj][mxi] = 0;
			if (mxi == 0)
				break;
			//cerr << cnt[mxi][mxj] + cnt[mxj][mxi] << "\n";
		}
		
		cerr << "OK " << test << "\n";
		
		cout << n << "\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		/*
		fclose (stdin);
		fclose (stdout);
		*/
	}

	return 0;
}