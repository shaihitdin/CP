#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100, sz = 6e4;

vector <int> d[sz];
int mask[N], score[N], k;
int pw3[15];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline void rec (const int &pos, const int &pow3, const int &mask, const int &nmask, const int &score) {
	if (pos == k) {
		d[nmask].emplace_back (score);
		return;
	}
	if (bit (mask, pos)) {
		rec (pos + 1, pow3 * 3, mask, nmask + pow3, score);
	} else {
		rec (pos + 1, pow3 * 3, mask, nmask + pow3 * 2, score);
	}
	rec (pos + 1, pow3 * 3, mask, nmask, score);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d%d", &score[i], &x);
		while (x--) {
			int f;
			scanf ("%d", &f);
			--f;
			mask[i] |= (1 << f);
		}
		rec (0, 1, mask[i], 0, score[i]);
	}

	pw3[0] = 1;

	for (int i = 1; i <= 10; ++i)
		pw3[i] = pw3[i - 1] * 3;
	
	for (int i = 0; i < sz; ++i) {
		sort (d[i].begin (), d[i].end ());
		//reverse (d[i].begin (), d[i].end ());
	}	

	int m;
	scanf ("%d", &m);
	
	while (m--) {
		int x, t;
		scanf ("%d%d", &x, &t);
		int mask1 = 0;
		while (t--) {
			int a;
			scanf ("%d", &a);
			--a;
			if (bit (mask[x], a))
				mask1 += pw3[a];
			else
				mask1 += pw3[a] * 2;
		}
		printf ("%d\n", d[mask1].end () - upper_bound (d[mask1].begin (), d[mask1].end (), score[x]) + 1);
	}
	
	return 0;
}