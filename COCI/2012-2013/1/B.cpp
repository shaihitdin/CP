#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
const int N = 4e5;
ll a[N], n, mx, ans, mxcnt;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%I64d", &a[i]);
		if (mx == a[i]) {
			++mxcnt;
		}
		if (mx < a[i]) {
			mx = a[i];
			mxcnt = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] + n >= mx + 1)
			++ans;
	}
	printf ("%I64d", (ans - mxcnt));
	return 0;
}