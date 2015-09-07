#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int l[N], r[N], cnt[N];


int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n;
	cin >> n;

	for (int i = 1; i < N; ++i)
		l[i] = N;
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		l[x] = min (l[x], i);
		r[x] = max (r[x], i);
	}

	int mx = -1;
	int al, ar;
	
	for (int i = 1; i < N; ++i) {
		if (mx < cnt[i] || (mx == cnt[i] && ar - al > r[i] - l[i])) {
			mx = cnt[i];
			al = l[i];
			ar = r[i];
		}
	}
	
	cout << al << " " << ar;
	
	return 0;
}