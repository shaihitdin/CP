#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;

int n, test;

#define end hahah

int a[N], cnt[N], end[N], go[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	
	cin >> n >> test;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i], a[i + n] = a[i];

	for (; test; --test) {
		
		long long s;
		
		cin >> s;

		for (int i = 1, j = 0; i <= n + n; s += a[i++]) {
			while (j + 1 <= n + n + 1 && s >= a[j + 1])
				s -= a[++j];
			go[i] = j + 1;
		}
		
		for (int i = 1; i <= n + n; ++i)
			end[i] = i, cnt[i] = 0;
		
		int ans (n);

		for (int i = n; i; --i) {
			if (go[i] > n)
				cnt[i] = 1, end[i] = go[i] - n;
			else
				cnt[i] = cnt[go[i]] + 1, end[i] = end[go[i]];
			if (end[i] >= i)
				ans = min (ans, cnt[i]);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}