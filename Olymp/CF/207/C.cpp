#include <bits/stdc++.h>

using namespace std;

int cnt[5], rans = 1e9, now;

inline void rec (const int &lvl) {
	if (lvl == 7 || now >= rans)
		return;
	if (cnt[1] == 0 && cnt[2] == 0) {
		rans = now;
		return;
	}
	int val, pen;
	val = cnt[1] / 2;
	if (val > 0) {
		pen = val;
		cnt[2] += val;
		cnt[1] = cnt[1] & 1;
		now += pen;
		rec (lvl + 1);
		cnt[2] -= val;
		cnt[1] += val * 2;
		now -= pen;
	}
	val = cnt[1] / 3;
	if (val > 0) {
		pen = 2 * val;
		cnt[3] += val;
		cnt[1] = cnt[1] % 3;
		now += pen;
		rec (lvl + 1);
		cnt[3] -= val;
		cnt[1] += val * 3;
		now -= pen;
	}
	val = min (cnt[1], cnt[2]);
	if (val > 0) {
		pen = val;
		cnt[2] -= val;
		cnt[1] -= val;
		cnt[3] += val;
		now += pen;
		rec (lvl + 1);
		cnt[3] -= val;
		cnt[2] += val;
		cnt[1] += val;
		now -= pen;
	}
	val = cnt[2] / 2;
	if (val > 0) {
		pen = 2 * (val);
		cnt[4] += val;
		cnt[2] = cnt[2] & 1;
		now += pen;
		rec (lvl + 1);
		cnt[4] -= val;
		cnt[2] += val * 2;
		now -= pen;
	}
	val = cnt[2] / 3;
	if (val > 0) {
		pen = 2 * (val);
		cnt[2] = cnt[2] % 3;
		cnt[3] += val;
		now += pen;
		rec (lvl + 1);
		cnt[3] -= val;
		cnt[2] += val * 3;
		now -= pen;
	}
	val = min (cnt[4], cnt[2]);
	if (val > 0) {
		pen = val;
		cnt[4] -= val;
		cnt[2] -= val;
		cnt[3] += val;
		now += pen;
		rec (lvl + 1);
		cnt[4] += val;
		cnt[2] += val;
		cnt[3] -= val;
		now -= pen;
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		if (x == 0)
			continue;
		++cnt[x];
	}
	
	rec (1);
	
	cout << rans << " ";
	return 0;
}