#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;
#define mkp make_pair
#define F first
#define S second
long long n, a[2001], ans;
unordered_map <int, int> cnt;
unordered_map <long long, int> cnt1;
int main () {
	freopen ("F.in", "r", stdin);
	freopen ("F.out", "w", stdout);
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%I64d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			ans += (cnt[-(a[i] + a[j])] - cnt1[-( (a[i] + a[j]) << 22) + a[i]] - cnt1[-( (a[i] + a[j]) << 22) + a[j]]);
		for (int j = i + 1; j <= n; ++j) {
			++cnt[a[i] + a[j]];		
			++cnt1[( (a[i] + a[j]) << 22) + a[i]];
			++cnt1[( (a[i] + a[j]) << 22) + a[j]];
		}
	}
	printf ("%I64d", ans / 3);
	return 0;
}