#include <bits/stdc++.h>

using namespace std;

#define y1 can

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int x1, y1, x2, y2;
	
	cin >> x1 >> y1 >> x2 >> y2;

	if ((x1 & 1) ^ (y1 & 1) != (x2 & 1) ^ (y2 & 1)) {
		cout << -1;
	} else if (x1 == x2 && y1 == y2) {
		cout << 0;
	} else if (abs (x1 - x2) == abs (y1 - y2)) {
		cout << 1;
	} else {
		cout << 2;
	}
	
	return 0;
}