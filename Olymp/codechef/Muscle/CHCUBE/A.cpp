#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		string a[10];
		
		for (int i = 1; i <= 6; ++i)
			cin >> a[i];

		if (a[1] == a[3] && (a[6] == a[3] || a[5] == a[3])) {
			cout << "YES\n";
		} else if (a[2] == a[3] && (a[6] == a[2] || a[5] == a[2])) {
			cout << "YES\n";
		} else if (a[2] == a[4] && (a[6] == a[2] || a[5] == a[2])) {
			cout << "YES\n";
		} else if (a[4] == a[1] && (a[6] == a[4] || a[5] == a[4])) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}