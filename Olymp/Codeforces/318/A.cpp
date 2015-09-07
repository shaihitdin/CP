#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int a[N], n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		while (a[i] % 2 == 0)
			a[i] /= 2;
		while (a[i] % 3 == 0)
			a[i] /= 3;
	}

	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[1]) {
			cout << "No";
			return 0;
		}
	}
	
	
	cout << "Yes";
	return 0;
}