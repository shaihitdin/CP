#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 100;

typedef long long ll;

ll ans[N], d[N];
ll lp[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int t;

	scanf ("%d", &t);

	for (int i = 2; i < N; ++i)
		if (!lp[i])
			for (int k = i; k < N; k += i)
				lp[k] = i;

	for (int i = 2; i < N; ++i) {
		ans[i] = ans[i / lp[i]] + 1;
	}
	
	for (int i = 1; i < N; ++i)
		d[i] = d[i - 1] + ans[i];
	
	for (int test = 1; test <= t; ++test) {
		int a, b;
		scanf ("%d%d", &a, &b);
		printf ("%d\n", d[a] - d[b]);
	}

	return 0;
}