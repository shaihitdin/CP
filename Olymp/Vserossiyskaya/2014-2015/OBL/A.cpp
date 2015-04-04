#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, l, r;
long long ans;
int main () {

	freopen ("hall.in", "r", stdin);
	freopen ("hall.out", "w", stdout);
	cin >> a >> b >> c >> d;
	for (int i = 1; i * i <= b; ++i) {
		l = a / i + (a % i != 0);
		r = b / i;
		l = max (l, i);
		l = max (l, (c - 2 * i) / 2 + ((c - 2 * i) % 2 != 0));
		r = min (r, (d - 2 * i) / 2);
		ans += max ((r - l) + 1, 0);
	}
	cout << ans;
	return 0;
}