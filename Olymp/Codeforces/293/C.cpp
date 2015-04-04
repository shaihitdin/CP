#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 20;

long long ans;
int n, m, k;
int a[N], aa[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		aa[a[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		int moves = (aa[x] - 1) / k + 1;
		if (aa[x] != 1) {
			int temp = a[aa[x] - 1];
			swap (a[aa[x]], a[aa[x] - 1]);
			++aa[temp];
			--aa[x];
		}
		ans += moves;
	}
	cout << ans;
	return 0;
}