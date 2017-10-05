#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 100;

int add[N], good[N], n, k, q;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k >> q;


	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		add[l]++;
		add[r + 1]--;
	}
	
	for (int i = 1, now = 0; i <= 2e5; ++i) {
		now += add[i];
		if (now >= k)
			good[i]++;
		good[i] += good[i - 1];
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << good[r] - good[l - 1] << "\n";
	}
	
	return 0;
}