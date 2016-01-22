#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int n, a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort (a + 1, a + n + 1);

	int i = 1, j = n;
	
	for (int cnt = 1; cnt <= n - 2; ++cnt) {
		if (cnt & 1) {
			if (a[j - 1] - a[i] < a[j] - a[i + 1]) {
				--j;
			} else {
				++i;
			}
		} else {
			if (a[j - 1] - a[i] > a[j] - a[i + 1]) {
				--j;
			} else {
				++i;
			}
		}
	}
	
	cerr << a[j] << " " << a[i];
	
	cout << a[j] - a[i];
	
	return 0;
}