#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fe first
#define se second

const int N = 1e5 + 100;

map <pair <int, int>, pair <int, int> > Map;
int n, a[N], b[N], c[N], d[N][4];
int ans, ans1, ans2;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j)
			cin >> d[i][j];
		sort (d[i] + 1, d[i] + 4);
		a[i] = d[i][1];
		b[i] = d[i][2];
		c[i] = d[i][3];
		if (min (a[i], min (b[i], Map[mp (a[i], b[i])].fe + c[i]) ) > ans) {
			ans = min (a[i], min (b[i], Map[mp (a[i], b[i])].fe + c[i]) );
			ans1 = i;
			ans2 = Map[mp (a[i], b[i])].se;
		}
		if (min (a[i], min (c[i], Map[mp (a[i], c[i])].fe + b[i])) > ans) {
			ans = min (a[i], min (c[i], Map[mp (a[i], c[i])].fe + b[i]));
			ans1 = i;
			ans2 = Map[mp (a[i], c[i])].se;
		}
		if (min (b[i], min (c[i], Map[mp (b[i], c[i])].fe + a[i])) > ans) {
			ans = min (b[i], min (c[i], Map[mp (b[i], c[i])].fe + a[i]));
			ans1 = i;
			ans2 = Map[mp (b[i], c[i])].se;
		}
		Map[mp (a[i], b[i])] = max (mp (c[i], i), Map[mp (a[i], b[i])]);
		Map[mp (b[i], c[i])] = max (mp (a[i], i), Map[mp (b[i], c[i])]);
		Map[mp (a[i], c[i])] = max (mp (b[i], i), Map[mp (a[i], c[i])]);
	}

	if (ans2 == 0) {
		cout << "1\n" << ans1;
	} else {
		cout << "2\n" << ans1 << " " << ans2;
	}
	
	return 0;
}