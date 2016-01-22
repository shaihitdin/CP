#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, K = 210;

typedef long long ll;

ll d[K][N];
int p[K][N];

const ll oo = 1e15;
int n, k, a[N], sum[N];

int main () {

	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;

	++k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	
	for (int i = 0; i <= k; ++i)
		for (int j = 0; j <= n; ++j)
			d[i][j] = -oo;	

	for (int i = 0; i <= k; ++i)
		d[i][0] = 0;
	
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			for (int l = p[j][i - 1]; l <= p[j - 1][i]; ++l) {
				ll x = sum[i] - sum[l];
				if (d[j][i] < d[j - 1][l] + x * (sum[n] - sum[l] - x)) {
					d[j][i] = d[j - 1][l] + x * (sum[n] - sum[l] - x);
					p[j][i] = l;
				}
			}
		}
	}

	
	cout << d[k][n] << "\n";

	int x = n, y = k;

	vector <int> ans;
	
	while (y > 1) {
		x = p[y][x];
		--y;
		ans.emplace_back (x);
	}

	for (int it : ans)
		cout << it << " ";
	
	return 0;
}