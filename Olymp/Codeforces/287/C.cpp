#include <iostream>
#include <stdio.h>
using namespace std;
long long ans, h, n, l, r;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> h >> n;
	l = 1;
	r = (1LL << h);
	ans = h;
	long long mid;
	long long can = 0;
	for (long long i = 0; i < h; ++i) {
		mid = (r + l) >> 1LL;
		if (!can) {
			if (n > mid) {
				ans += (1LL << (h - i)) - 1; 
				l = mid + 1;
				can = 0;
			} else {
				r = mid;
				can = 1;
			}
		} else {
			if (n <= mid) {
				ans += (1LL << (h - i)) - 1; 
				r = mid;
				can = 1;
			} else {
				can = 0;
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}