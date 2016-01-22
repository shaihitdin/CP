#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("monotony.in", "r", stdin);
	freopen ("monotony.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	int n;	
	cin >> n;
	int lst = -1, len = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x > lst) {
			++len;
			mx = max (mx, len);
		} else {
			len = 1;
		}
		lst = x;
	}

	mx = max (mx, len);

	cout << mx;
	
	return 0;
}