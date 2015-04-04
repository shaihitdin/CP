#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
long long a[N], ans;
long long t, n;
int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);	
	scanf ("%lld", &t);
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			scanf ("%lld", &a[i]);
		ans = 0;
		sort (a + 1, a + n + 1);
		int l1 = n, r1 = n - 1;
		for (;;) {
			if (l1 == r1)
				--r1;
			long long temp = min (a[l1], a[r1]);
			ans += temp;
			a[l1] -= temp;
			a[r1] -= temp;
			if (!a[l1])
				--l1;
			if (!a[r1])
				--r1;
			if (r1 < 1)
				break;
		}
		ans += a[l1];
		cout << ans << "\n";
	}
	return 0;
}