#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("in", "w", stdout);

	int n, m;

	n = m = 300;

	cout << n << " " << m << "\n";

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << rand () << " ";
		}
		cout << "\n";
	}
			

	return 0;
}