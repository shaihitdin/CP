#include <bits/stdc++.h>

using namespace std;

int a[7];

int main () {

	#ifdef LOCAL
	freopen ("scales.in", "w", stdout);
	#endif

	cout << "720\n";

	int n = 6;

	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	
	do {
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << "\n";
	} while (next_permutation (a, a + n));
	
	
	return 0;
}