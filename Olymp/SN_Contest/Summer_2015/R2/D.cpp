#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 100;

int len[N];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		int x, h;
		cin >> x >> h;
		len[x] = h;
	}

	int i, ans = 0;
	for (i = k - 1; i >= 1; --i) {
		if (len[i])
			break;
	}
	
	if (i != 0) {
		int till = max (1, i - len[i]);
		++ans;
		for (int j = i - 1; j >= till; --j) {
			if (len[j]) {
				++ans, till = min (till, max (1, j - len[j]));
			}
		}
	}
	
	for (i = k + 1; i <= 1e7; ++i) {
		if (len[i])
			break;
	}
	
	if (i != 1e7 + 1) {
		int till = min (N - 1, i + len[i]);
		++ans;
		for (int j = i + 1; j <= till; ++j) {
			if (len[j]) {
				++ans, till = max (till, min (N - 1, j + len[j]));
			}
		}
	}

	cout << ans;
	
	return 0;
}