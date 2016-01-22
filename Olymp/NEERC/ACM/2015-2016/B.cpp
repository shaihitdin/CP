#include <bits/stdc++.h>

using namespace std;

char a[3010][11];
int n, m;
int w, b;

inline void print () {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << a[i][j];
		cout << "\n";
	}
	exit (0);
}

int main () {

	freopen ("black.in", "r", stdin);
	freopen ("black.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> b >> w;

	memset (a, '.', sizeof (a));

	n = 3000, m = 10;
	
	cout << n << " " << m << endl;

	if (w == 1) {
		int cntb = 0;
		for (int i = 1; i <= n; i += 2) {
			for (int j = 1; j <= m; j += 2) {
				if (cntb == b)
					print ();
				a[i][j] = '@';
				++cntb;
			}
		}
		print ();
	}
	
	
	int cntw = 2, cntb = 1;
	
	for (int i = 1; i <= n; ++i)
		a[i][2] = '@';

	for (int i = 2; i <= n && cntw + 1 <= w; i += 2, ++cntw) {
		a[i][1] = '@';
	}
	
	for (int i = 1; i <= n; i += 2) {
		for (int j = 4; j <= m; j += 2) {
			if (cntb == b)
				print ();
			a[i][j] = '@';
			++cntb;
		}
	}
	
	
	return 0;
}