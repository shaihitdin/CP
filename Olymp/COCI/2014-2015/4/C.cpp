#include <iostream>
#include <assert.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = (3e5) + 1;;
long long a[N];
int le[3][N];
long long last_ans, ans, n, t;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		le[1][i] = a[i], le[2][i] = a[i];
	int i = 1, j = n, t = 0;
	while (i < j) {
		ans += le[2][j];
		t = le[2][j];
		le[2][j] = 0;
		while (t && (i < j)) {
			int x = min (t, le[1][i]);
			t -= x;
			le[1][i] -= x;
			if (!le[1][i])
				++i;
			int ss;
			cerr << t << " " << i << " " << j << " " << (i == j) << "%%";
		}
		--j;
	}
	long long temp = 0;
	long long temp1 = 0;
	if (le[1][i] != a[i]) {
		// j must do smth else
		for (int k = i - 1; k >= 1; --k) {
			temp += le[2][k];
			le[2][k] = 0;
		}
		for (int k = i; k <= n; ++k) {
			temp1 += le[1][k];
			le[1][k] = 0;
		}
		ans += max (temp + max (a[i] - temp, 0LL) + a[i], temp1 - t);
	}
	else {
		// i must do smth else
		for (int k = j + 1; k <= n; ++k) {
			temp += le[1][k];
			le[1][k] = 0;
		}
		for (int k = j; k >= 1; --k) {
			temp1 += le[2][k];
			le[2][k] = 0;
		}	
		cerr << temp << " " << t << " " << a[i] << " " << temp1 << " "; 
		ans += max (temp - t + max (a[i] - temp, 0LL) + a[i], temp1);
	}
	printf ("%lld", ans);
	return 0;
}