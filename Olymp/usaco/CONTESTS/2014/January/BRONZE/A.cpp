#include <iostream>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
using namespace std;
const long long N = 10003;
const long long inf = 1e18;
const double eps = 1 / 1e5;
char q[N];
double m[N], d[N], t[N], mnd, mnt;
int n, mnpos;
double ans;
int main () {
	freopen ("slowdown.in", "r", stdin);
	freopen ("slowdown.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> q[i] >> m[i];
	for (int i = 1; i <= n; ++i) {
		mnd = inf;
		mnt = inf;
		mnpos = 0;
		for (int j = 1; j <= n; ++j) {
			if (q[j] == 'T') {
				if (mnt > m[j]) {
					mnt = m[j];
					mnd = d[i - 1] + ((m[j] - t[i - 1]) / (double) (i));
					mnpos = j;
				}
			}
			if (q[j] == 'D') {
				if (mnd > m[j]) {
					mnd = m[j];
					mnt = t[i - 1] + ((m[j] - d[i - 1]) * (double) (i));
					mnpos = j;
				}
			}
		}
		assert (mnpos != 0);
		d[i] = mnd;
		t[i] = mnt;
		m[mnpos] = inf;
	}
	d[n + 1] = 1000;
	for (int i = 1; i <= n + 1; ++i)
		ans += ((d[i] - d[i - 1]) * (double) (i));
	if (ans - double((long long) ans + 0.5) > 0 || ans - double((long long) ans + 0.5) > -eps)
		cout << (long long) ans + 1;	
	else
		cout << (long long) ans;
	return 0;
}