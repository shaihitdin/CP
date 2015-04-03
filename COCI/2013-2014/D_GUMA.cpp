#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100001;
long long ans;
int n, a[N];
bool u[N];
inline int gcd (const int &x, const int &y) {
	return y ? gcd (y, x % y) : x;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	sort (a, a + n + 1);
	for (int i = n; i >= 0; --i) {
		bool flag = 0;
		for (int j = a[i]; j < N; j += a[i]) {
			if (u[j]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			ans += (a[i] - 1);
			u[a[i]] = 1;
		}
	}
	printf ("%I64d", ans);
	return 0;
}