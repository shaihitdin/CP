#include <bits/stdc++.h>

using namespace std;

#define prev can


const int N = 3e6 + 100, inf = 1e9;

int ans = inf;

int cnt[N], n, a[N], nxt[N], prev[N];

int f_m[N];

inline int get_l (const int &l, const int &r) {
	int now = prev[f_m[r]];
	if (f_m[l] <= f_m[r]) {
		if (now < f_m[l])
			now = -1;
		return now;
	}

	if (now == -1)
		return get_l (f_m[l], n - 1);

	return now;
}


inline int get_f (const int &l, const int &r) {
	int now = nxt[f_m[l]];
	if (f_m[l] <= f_m[r]) {
		if (now > f_m[r])
			now = -1;
		return now;
	}

	if (now == -1)
		return get_f (0, f_m[r]);

	return now;
}

inline void solve () {
	memset (cnt, 0, sizeof (cnt));
	for (int i = 1; i <= n; ++i)
		++cnt[f_m[a[i] - i + n]];

	nxt[n] = -1;
	for (int i = n - 1; i != -1; --i)
		if (cnt[i])
			nxt[i] = i;
		else
			nxt[i] = nxt[i + 1];
	prev[0] = cnt[0] ? 0 : -1;
	for (int i = 1; i < n; ++i)
		if (cnt[i])
			prev[i] = i;
		else
			prev[i] = prev[i - 1];
	for (int st = 0; st < n; ++st) {
		int half = (n - 1) >> 1;
		int cw = get_f (st + half + 1, st + n - 1), ccw = get_l (st, st + half);
		
		if (cw != -1)
			cw = f_m[cw - st + n];
		if (ccw != -1)
			ccw = f_m[ccw - st + n];

		if (cw == -1)
			cw = n;
		
		ans = min (ans, max (n - cw, ccw));
	}
}


int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	scanf ("%d", &n);
	
	for (int i = 0; i <= 3 * n; ++i)
		f_m[i] = i % n;
	
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	if (n == 1) {
		printf ("0");
		return 0;
	}
	
	solve ();
	reverse (a + 1, a + n + 1);
	solve ();
	
	assert (ans >= 0);
	
	printf ("%d", ans);
	
	return 0;
}