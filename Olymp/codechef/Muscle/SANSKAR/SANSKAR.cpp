#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
long long need;
vector <int> res;
bool flag;
int n, t, k;
int a[22];
inline void rec2 (const int &v, const int &mask) {
	if (v == res.size() ) {
		if (!flag && mask == (1 << n) - 1) {
			printf ("yes\n");
			flag = 1;
		}
		return;
	}
	if ( (mask & res[v]) == 0) {
		rec2 (v + 1, (mask | res[v]) );
	}
	rec2 (v + 1, mask);
}

inline void rec (const int &v, const int &mask, const long long &sz) {
	if (v == n) {
		if (sz == need)
			res.push_back (mask);
		return;
	}
	if (sz + a[v] <= need)
		rec (v + 1, mask | (1 << v), sz + a[v]);
	rec (v + 1, mask, sz);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	++t;
	while (--t) {
		scanf ("%d%d", &n, &k);
		long long sum = 0;
		flag = 0;
		res.clear();
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &a[i]);
			sum += a[i];
		}
		if (sum % k != 0) {
			printf ("no\n");
			continue;
		}
		need = sum / k;
		rec (0, 0, 0);
		rec2 (0, 0);
		if (!flag) {
			printf ("no\n");
		}
	}
	return 0;
}