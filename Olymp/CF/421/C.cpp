#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif


	int a, b, l, r;

	cin >> a >> b >> l >> r;

	--l, --r;

	int x = a + b;

	if (r - l + 1 >= x) {
		cout << a + 1;
		return 0;                                                                                                                                       
	}

	r %= x;
	l %= x;

	++l;
	++r;
	
	
	int ans = 0;
	int times = 0;
	if (r < l) {
		if (r > a) {
			cout << a + 1;
			return 0;
		}
		times = a - min (a, l) + 1;
		times += r;
		times -= min (b, a - min (a, l) + 1);
	} else {
		if (l > a) {
			cout << 1;
			return 0;
		}
		times = min (a, r) - l + 1;
	}
	
	cout << times;	
	return 0;
}