#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void upd (const int &x, const int &y, const int &delta) {
	for (int i = x; i < N; i |= (i + 1))
		for (int j = y; j < N; j |= (j + 1))
			t[i][j] ^= delta;
}

inline ll get (const int &x, const int &y) {
	ll res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			res ^= t[i][j];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d", &n, &m);



	return 0;
}