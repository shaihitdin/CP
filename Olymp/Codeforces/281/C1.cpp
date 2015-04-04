#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 600005;
int n, a[N], m, b[N];
vector <int> v;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf ("%d", &b[i]);
	for (int i = 1; i <= n; ++i) {
		v.push_back (a[i]);
		v.push_back (a[i] - 1);
	}
	for (int i = 1; i <= m; ++i) {
		v.push_back (b[i]);
		v.push_back (b[i] - 1);
	}
	int i = 0, j = 0;
	sort (v.begin (), v.end ());
	sort (a + 1, a + n + 1);
	sort (b + 1, b + m + 1);
	b[0] = a[0] = -2000000001;
	b[m + 1] = a[n + 1] = 2000000001;
	int mxi = -2000000001, mxj = -2000000001, mx = -2000000001;
	for (int x : v) {
		while (a[i + 1] <= x)	++i;
		while (b[j + 1] <= x)	++j;
		int c1 = i * 2 + (n - i) * 3,
		c2 = j * 2 + (m - j) * 3;
		if (c1 - c2 > mx || (c1 - c2 == mx && c1 > mxi)) {
			mxi = c1;
			mxj = c2;
			mx = c1 - c2;
		}		
	}
	printf ("%d:%d", mxi, mxj);
	return 0;
}