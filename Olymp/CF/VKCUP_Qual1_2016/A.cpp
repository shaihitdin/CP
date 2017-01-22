#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int mxpos, cnt[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (++cnt[x] > cnt[mxpos])
			mxpos = x;
	}

	cout << mxpos;
	
	return 0;
}