#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4 + 100;

int a[N], b[N], n, m;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		for (int i = 1, j = l; j <= r; ++j, ++i)
			b[i] = a[j];
		random_shuffle (b + 1, b + (r - l + 1) + 1);
		nth_element (b + 1, b + x - l + 1, b + (r - l + 1) + 1);
		if (b[x - l + 1] == a[x])
			puts ("Yes");
		else
			puts ("No");
	}		
	
	return 0;
}