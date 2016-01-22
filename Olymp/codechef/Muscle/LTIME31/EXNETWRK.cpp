#include <bits/stdc++.h>

using namespace std;

const int N = 300;

vector <pair <int, int> > d[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	/*
	d[1][0] = 1;
	
	for (int i = 3; i <= 10; ++i)
		d[i][i] = 1;
	
	for (int i = 0; i <= 10; ++i) {
		for (int i1 = 0; i1 <= 10; ++i1) {
			for (int j = 0; j <= 100; ++j) {
				for (int j1 = 0; j1 <= 100; ++j1) {
					if (i == 1 && j == 0)
						continue;
					if (i1 == 1 && j1 == 0 && i <= 3)
						continue;					
					d[i + i1][j + j1 + 2] |= (d[i][j] & d[i1][j1]);
				}
			}
		}
	}
	
	for (int i = 0; i <= 10; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (d[i][j])
				cerr << i << " " << j << "\n";
		}
	}
	*/

	
	for (int i = 3; i <= 100; ++i) {
		for (int j = 1; j < i; ++j) {
			d[i][i].emplace_back (make_pair (j, j + 1));
		}
		d[i][i].emplace_back (make_pair (1, i));
	}
	
	for (int i = 0; i <= 100; ++i) {
		for (int i1 = 0; i1 + i <= 100; ++i1) {
			for (int j = 0; j <= 200; ++j) {
				for (int j1 = 0; j1 + j <= 200; ++j1) {
					if (i == 1 && j == 0)
						continue;
					if (i1 == 1 && j1 == 0 && i <= 3)
						continue;
					if (!d[i][j].size ())
						continue;
					if (!d[i1][j1].size () || (!(i1 == 1 && j1 == 0)))
						continue;
					if (d[i + i1][j + j1 + 2].size ())
						continue;
					d[i + i1][j + j1 + 2] = d[i][j];
					for (auto it : d[i1][j1])
						d[i + i1][j + j1 + 2].emplace_back (it.first + i, it.second + i);
					d[i + i1][j + j1 + 2].emplace_back (make_pair (i, i + 1));
					d[i + i1][j + j1 + 2].emplace_back (make_pair (2, i + 1));
					//d[i + i1][j + j1 + 2] |= (d[i][j] & d[i1][j1]);
				}
			}
		}
	}
	
	ios_base :: sync_with_stdio (0);
	
	int t;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n <= 4) {
			if (n == 1) {
				if (m != 0) {
					cout << "-1 -1\n";
				}
				continue;
			}
			if (n != m) {
				cout << "-1 -1\n";
				continue;
			}
			for (int i = 1; i < n; ++i)
				cout << i << " " << i + 1 << "\n";
			cout << 1 << " " << n << "\n";			
			continue;
		}
		if (!d[n][m].size ()) {
			cout << "-1 -1\n";
			continue;
		}
		for (auto it : d[n][m])
			cout << it.first << " " << it.second << "\n";
	}

	return 0;	
}