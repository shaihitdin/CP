#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
const int N = (1e9) + 1;
int speed[100001], n, previous, ans;
map <int, int> t;
inline void upd (const int &r, const int &inc) {
	for (int i = r; i < N; i = i | (i + 1) )
		t[i] += inc;
	return;
}
inline int get (const int &r) {
	int res = 0;
	for (int i = r; i >= 1; i = (i & (i + 1) ) - 1)
		res += t[i];
	return res;
}
int main () {
	freopen ("cowjog.in", "r", stdin);
	freopen ("cowjog.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%*d%d", &speed[i]);
		upd (speed[i], 1);	
	}
	for (int i = 1; i <= n; ++i) {
		if (get (speed[i] - 1) == 0)
			++ans;
		upd (speed[i], -1);
	}
	printf ("%d\n", ans);
	return 0;
}