#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	int n = 1000;

	cout << n * 2 << "\n";
	
	for (int i = 1; i <= n; ++i)
		cout << i << " " << 1 << "\n" << i << " " << 2 << "\n";
	
	for (int i = n; i >= 1; --i)
		cout << i << " " << 1 << "\n" << i << " " << 2 << "\n";
	
	return 0;
}