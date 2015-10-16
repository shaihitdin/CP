#include <iostream>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N = 200001;
int n, a[N], m, b[N];
inline pair <int, int>  calc (const int &x) {
	int a_count = 0;
	int b_count = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] > x)
			a_count += 3;
		else
			a_count += 2;
	for (int i = 1; i <= m; ++i)
		if (b[i] > x)
			b_count += 3;
		else
			b_count += 2;
	return mkp (a_count, b_count);		 
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	int l = 0,
	r = 0;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		r = max (r, a[i]);
	}
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &b[i]);
		r = max (r, a[i]);
	}
	++r;
	while (r - l >= 10) {
		int mid1 = l + (r - l) / 3,
		mid2 = r - (r - l) / 3;
		pair <int, int> get1 = calc (mid1),
		get2 = calc (mid2);

		if ( abs (get1.F - get1.S) > abs (get2.F - get2.S) )
			r = mid2;
		else
			l = mid1;
	}
	int mx = -2000000002, mxf = -2000000002, mxs = -2000000002;
	int temp;
	for (; l <= r; ++l) {
		pair <int, int> get = calc (l);
		if (abs (get.F - get.S) > mx) {
			mxf = get.F;
			mxs = get.S;
			mx = get.F - get.S;
			temp =  l;
		} 
		else if (mx == abs (get.F - get.S)  && get.F > mxf) {
			mxf = get.F;
			mxs = get.S;
			temp = l;		
		}
	}
	printf ("%d:%d", mxf, mxs);
	return 0;
}