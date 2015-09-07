#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n = 1e5;
	
	cout << n << endl;

	for (int i = 1; i <= n; ++i) {
		cout << i;
		if (i < n)
			cout << " ";
	}
	
	cout << endl;

	return 0;
}