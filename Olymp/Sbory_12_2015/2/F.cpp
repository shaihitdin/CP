#include <bits/stdc++.h>


using namespace std;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int t;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) {
			int a, b;
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}

	return 0;
}