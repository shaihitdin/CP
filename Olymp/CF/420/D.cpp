#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int n, m, k;
int st[N], stq = 2e4, enq = 2e4, d[N], x[N], y[N];


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> k;

	for (int i = 1; i <= k; ++i) {
		cin >> x[i] >> y[i];
	}
	
	for (int i = 1; i <= k; ++i) {
		if (x[i] == 1 && y[i] == 1) {
			d[i] = 1;
			st[++enq] = i;
		}
	}	
	
	while (stq != enq) {
		int v = st[++stq];
		for (int i = 1; i <= k; ++i) {
			if (abs (x[i] - x[v]) + abs (y[i] - y[v]) == 1 && (!d[i] || d[i] > d[v])) {
				d[i] = d[v];
				st[stq--] = i;
			}
			/*
			if ((x[i] == x[v] || y[i] == y[v]) && !d[i]) {
				d[i] = d[v] + 1;
				st[++enq] = i;
			}
			*/
			if ((abs (x[i] - x[v]) <= 2 || abs (y[i] - y[v]) <= 2) && !d[i]) {
				d[i] = d[v] + 1;
				st[++enq] = i;
			}
		}
	}
		
	for (int i = 1; i <= k; ++i)
		if (!d[i])
			d[i] = 1e9 + 1;
	
	int ans = 1e9 + 1;
	
	for (int i = 1; i <= k; ++i) {
		if (x[i] == n && y[i] == m) {
			ans = min (ans, d[i]);
		}
		if (x[i] >= n - 1 || y[i] >= m - 1) {
			ans = min (ans, d[i] + 1);
		}
	}
	
	--ans;
	if (ans == 1e9)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}