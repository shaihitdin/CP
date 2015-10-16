#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, bpr = 1e9 + 7, pr = 53;

inline int get_hash (const int &hash, const int &pw) {
	return (hash * 1ll * p[N - 1 - pw]) % bpr;
}


inline bool cmp (const int &x, const int &y) {
	int l = 0, r = n;
	int x1 = x, x2 = y;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		
	}
}


inline char ge (const int &i, const int &j) {
	if (j < i)
		return s[j];
	return s[j + 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	
	p[0] = 1;

	for (int i = 1; i < N; ++i)
		p[i] = (p[i - 1] * 1ll * pr) % bpr;
	
	for (int i = 1; i <= n; ++i)
		h[i] = (h[i - 1] + (((s[i] - 'a' + 1) * 1ll * p[i]) % bpr)) % bpr
	
	for (int i = 1; i <= n; ++i) {
		c[i] = i;
	}
	
	sort (c + 1, c + n + 1, cmp);
	
	return 0;
}