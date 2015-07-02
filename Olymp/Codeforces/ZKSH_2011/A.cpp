#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;

	for (int cnt = 1, i = 1; cnt <= n; i = (i + cnt) % n, ++cnt) {
		if (cnt == 1)
			continue;
		if (i != 0)
			cout << i << " ";
		else
			cout << n << " ";
	}

	return 0;
}