#include <bits/stdc++.h>

using namespace std;

set <vector <char> > s;

const int N = 1200;

int n, m;
char a[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	int l = 0, r = n + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		s.clear ();
		vector <char> tmp;
		for (int j = 1; j <= m; ++j) {
			tmp.resize (0);
			for (int i = mid + 1; i <= n; ++i) {
				tmp.emplace_back (a[i][j]);
			}
			if (!s.insert (tmp).second)
				r = mid;
		}
		if (r != mid)
			l = mid;
	}	
	
	cout << l;
	
	return 0;
}