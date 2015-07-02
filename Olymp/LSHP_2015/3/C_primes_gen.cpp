#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main () {
	#ifdef LOCAL
	freopen ("err", "w", stdout);
	#endif

	cin >> n;

	for (ll i = n, cnt = 10; cnt; ++i) {
		bool flag = 1;
		for (ll j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << i << " ";
			--cnt;
		}
	}

	return 0;
}