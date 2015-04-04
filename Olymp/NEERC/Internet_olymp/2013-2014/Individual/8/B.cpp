#include <math.h>
#include <stdio.h>

using namespace std;

const int N = 1e5 + 1, inf = 1e9;
int b[400], b_l[400], b_r[400];
int now[N], a[N], b_num[N], block;
inline void recac
inline void push (const int &block_num) {
	if (upd_to[block_num] != 0) {
		for (int i = b_l[block_num]; i <= b_r[block_num]; ++i)
			now[i] += upd_to[block_num];
		b[block_num] = inf;
		for (int i = b_l[block_num]; i <= b_r[block_num]; ++i)
			b[block_num] = min (b[block_num], a[i] - now[i]);
	}
}

inline int get (const int &l, const int &r) {
	int res = inf;
	int i = l;
	if (b_num[l] == b_num[r]) {
		push (b_num[l]);
		for (; i <= r; ++i)
			res = min (res, a[i] - now[i]);
		return res;
	}
	for (; b_num[i] == b_num[l]; ++i)
		res = min (res, a[i] - now[i]);
	for (; b_num[i] != b_num[r]; i += block)
		res = min (res, b[b_num[i]]);
	for (; i <= r; ++i)
		res = min (res, a[i] - now[i]);
	return res;
}

inline void update (const int &l, const int &r, const int &to) {
	if (b_num[l] == b_num[r]) {
		push (b_num[l]);
		for (; l <= r; ++l)
			now[l] += to;
		return;
	}
	int i = l;
	push (b_num[i]);
	for (; b_num[i] == b_num[l]; ++i)
		res = min (res, a[i] - now[i]);
	for (; b_num[i] != b_num[r]; i += block)
		res = min (res, b[b_num[i]]);
	for (; i <= r; ++i)
		res = min (res, a[i] - now[i]);
	return res;
}

int main () {
	freopen ("toy.in", "r", stdin);
	freopen ("toy.out", "w", stdout);
	scanf ("%d", &n);
	block = sqrt (n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		b_num[i] = i / block;
	}
	for (int i = 1; i < 400; ++i)
		b_l[i] = inf;
	for (int i = 1; i <= n; ++i) {
		b_l[block_num[i]] = min (b_l[block_num[i]], i);
		b_r[block_num[i]] = max (b_r[block_num[i]], i);
	}
	for (int i = 1; i <= n; ++i) {
		b[b_num[i]] = min (b[b_num[i]], a[i]);
	}
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &l, &r);
		
	}
	return 0;
}