#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 100, bpr = 1e9 + 7;

typedef long long ll;

#define int ll

int cnt[N];
int ans[N];

 main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	
	for (int i = 1; i < N; ++i) {
		for (int j = i, k = 1; j < N; j += i, ++k) {
			if (k == i)
				ans[j] += cnt[i] * (cnt[i] - 1);
			else
				ans[j] += cnt[i] * cnt[k];
		}
	}
	
	for (int i = 1; i < N; ++i)
		ans[i] += ans[i - 1];
	
	int total = n * (n - 1);

	int m;
	cin >> m;

	while (m--) {
		int x;
		cin >> x;
		cout << total - ans[x - 1] << "\n";
	}	
	
	return 0;
}