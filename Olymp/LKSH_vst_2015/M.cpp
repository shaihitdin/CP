#include <bits/stdc++.h>

using namespace std;

const int N = 3001, M = 1e5 + 1;

int n, q;
int a[N];

map <int, int> Map;
int c[N];

int ans[M];
vector <int> query[N][N];

int t[N];


inline int get (int r) {
	int res = 0;
	for (; r > 0; r = (r & (r + 1)) - 1)
		res = max (res, t[r]);
	return res;
}

inline void upd (int x, const int &change) {
	for (; x < N; x |= (x + 1))
		t[x] = max (t[x], change);
}

int main () {

	freopen ("segment-lis.in", "r", stdin);
	freopen ("segment-lis.out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	
	for (int i = 1; i <= n; ++i)
		c[i] = a[i];

	sort (c + 1, c + n + 1);
	
	int cnt = 0;
	
	for (int i = 1; i <= n; ++i)
		if (!Map.count (c[i]))
			Map[c[i]] = ++cnt;

	for (int i = 1; i <= n; ++i)
		a[i] = Map[a[i]];

	scanf ("%d", &q);

	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf ("%d%d", &l, &r);
		query[l][r].push_back (i);
	}

	for (int l = 1; l <= n; ++l) {
		memset (t, 0, sizeof (t));
		int res = 0;
		for (int r = l; r <= n; ++r) {
			int tmp = get (a[r] - 1);
			res = max (res, tmp + 1);
			upd (a[r], tmp + 1);
			for (auto it : query[l][r])
				ans[it] = res;
		}
	}

	for (int i = 1; i <= q; ++i)
		printf ("%d\n", ans[i]);
	
	return 0;
}