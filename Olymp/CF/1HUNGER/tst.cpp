#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif

	int n = 2e4;

	cout << n << " 0\n";

	for (int i = 1; i <= n; ++i)
		cout << 1 + (rand () % 60) << " ";

	return 0;
}