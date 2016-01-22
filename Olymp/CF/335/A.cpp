#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
int pos[N];
int srt[N], srt2[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		pos[x] = i;
	}

	int ans1 = 0;
	
	for (int i = n - 1; i >= 1; --i) {
		if (pos[i] > pos[i + 1]) {
			ans1 = n - i;
		}
		srt[i] = ans1;
	}

	int ans2 = 0;
	
	for (int i = 2; i <= n; ++i) {
		if (pos[i] < pos[i - 1]) {
			ans2 = i - 1;
		}
		srt2[i] = ans2;
	}
	
	int ans = 1e9;
	for (int i = 1; i <= n; ++i)
		ans = min (ans, srt2[i] + srt[i]);
	cout << ans;
	
	return 0;
}