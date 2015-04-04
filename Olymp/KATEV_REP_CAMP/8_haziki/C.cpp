#include <bits/stdc++.h>

using namespace std;

int t, g, l;

int main () {
	
	cin >> t;
	
	while (t--) {
		cin >> g >> l;
		if (l % g == 0)
			cout << g << " " << l << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}