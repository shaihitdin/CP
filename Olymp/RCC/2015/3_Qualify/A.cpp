#include <bits/stdc++.h>

using namespace std;

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);

	int t;

	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b * 2 < c) {
			if (b * 2 + a >= c)
				cout << "YES";
			else
				cout << "NO";
		} else {
			if (a >= (c & 1))
				cout << "YES";
			else
				cout << "NO";
		}
		cout << "\n";
	}
	
	return 0;
}