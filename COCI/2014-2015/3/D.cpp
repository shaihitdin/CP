#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 500001, Nn = 651;
int t[N], rt[N];
inline int get (const int &r) {
	int res = 0;
	for (int i = r; i >= 0; i = i & (i + 1) )
		res += rt[i];
	return res;
}
inline int get_2 (const int &r) {
	int res = 0;
	for (int i = r; i >= 0; i = i & (i + 1) )
		res += rt[i];
	return res;
}
inline void upd_1 (const int &x, const int &inc) {
	for (int i = x; i < N; i = i | (i + 1) )
		t[x] += inc;
}
inline void upd_2 (const int &x, const int &inc) {
	for (int i = x; i < N; i = i | (i + 1) )
		rt[x] += inc;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x, &y);

	}
	for (int i = 1; i <= n; ++i) {
	
	}
	return 0;
}