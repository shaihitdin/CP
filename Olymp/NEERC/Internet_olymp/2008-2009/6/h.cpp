#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 10010;

int d[N][N], d1[N][N];
int n, m, zz, p;
int x[M], y[M], z[M], a[M], b[M], c[M], s[M];

int main () {

	freopen ("roads.in", "r", stdin);
	freopen ("roads.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = 1e9;
	
	for (int i = 1; i <= m; ++i) {
		int z1, z2, z3;
		cin >> z1 >> z2 >> z3;
		d[z1][z2] = d[z2][z1] = z3;
	}

	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;	
	
	
	cin >> zz;

	for (int i = 1; i <= zz; ++i)
		cin >> x[i] >> y[i] >> s[i] >> z[i];

	cin >> p;

	for (int i = 1; i <= p; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	int l = 0, r = 1e9 + 2;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		memcpy (d1, d, sizeof (d));
		for (int i = 1; i <= zz; ++i)
			if (z[i] <= mid)
				d1[x[i]][y[i]] = min (d1[x[i]][y[i]], s[i]), d1[y[i]][x[i]] = min (d1[y[i]][x[i]], s[i]);
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					d1[i][j] = min (d1[i][j], d1[i][k] + d1[k][j]);
	
		for (int i = 1; i <= p; ++i) {
			if (d1[a[i]][b[i]] > c[i]) {
				l = mid;
				break;
			}
		}
	
		if (mid != l)
			r = mid;
	
	}

	
	
	vector <int> ans;
	
	for (int i = 1; i <= zz; ++i)
		if (z[i] <= r)
			ans.emplace_back (i);
	
	if (r == 1e9 + 2) {
		cout << -1;
		return 0;
	}
	
	cout << ans.size () << "\n";

	for (auto v : ans)
		cout << v << " ";
	
	return 0;
}