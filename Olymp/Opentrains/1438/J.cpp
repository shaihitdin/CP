#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100, oo = 1e9 + 7;

pair <int, int> d[2][N];
int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t, n;
	
	cin >> t >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		d[1][i] = make_pair (0, a[i]);
	}
	
	for (int len = 2; len <= n; ++len) {
		int v = len & 1;
		for (int l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			int f_1, f_2;
			d[v][l] = make_pair (oo, oo);
			f_1 = d[v ^ 1][l].first;
			f_2 = d[v ^ 1][l].second;
			if (f_2 + a[r] <= t)
				d[v][l] = min (d[v][l], make_pair (f_1, f_2 + a[r]));
			else
				d[v][l] = min (d[v][l], make_pair (f_1 + 1, a[r]));
			f_1 = d[v ^ 1][l + 1].first;
			f_2 = d[v ^ 1][l + 1].second;
			if (f_2 + a[l] <= t)
				d[v][l] = min (d[v][l], make_pair (f_1, f_2 + a[l]));
			else
				d[v][l] = min (d[v][l], make_pair (f_1 + 1, a[l]));
		}
	}
	
	cout << d[n & 1][1].first + (d[n & 1][1].second > 0);

	return 0;
}