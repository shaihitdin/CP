#include <bits/stdc++.h>

using namespace std;

const int N = 20, inf = 1e9;

struct state {
	int a[N];
	int res;
} cur, nxt, best;

int n, r[N], b[N];
char c[N];

inline void calc (state &cur) {
	int R = 0, B = 0, r_now = 0, b_now = 0;
	cur.res = 0;
	for (int i = 0; i < n; ++i) {
		int need = max (r[cur.a[i]] - (R + r_now), b[cur.a[i]] - (B + b_now));
		need = max (need, 0);
		cur.res += need;
		r_now += need;
		b_now += need;
		r_now -= max (r[cur.a[i]] - R, 0);
		b_now -= max (b[cur.a[i]] - B, 0);
		if (c[cur.a[i]] == 'R')
			++R;
		else
			++B;
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	srand (time (0));
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> c[i] >> r[i] >> b[i];
	}

	for (int i = 0; i < n; ++i)
		cur.a[i] = i;
	
	calc (cur);
	
	best = cur;

	double t = n, alpha = 0.99;

	while (clock () * 1000 / CLOCKS_PER_SEC < 1900) {
		nxt = cur;
		for (int i = 0; i <= int (t); ++i)
			swap (nxt.a[rand() % n], nxt.a[rand() % n]);
		calc (nxt);
		double d = (int)(nxt.res - cur.res);
		if (d < 0 || exp((-d) / t) > (rand() % 1024) / 1024)
			cur = nxt;
		if (cur.res < best.res) best = cur;
		t *= alpha;
	}

	cout << best.res + n;

	return 0;
}