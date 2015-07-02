#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int t[2][N], a[N];

inline void upd (const int &num, int r, const int &delta) {
	for (; r < N; r |= (r + 1))
		t[num][r] += delta;
}

inline int get (const int &num, int r) {
	int res = 0;
	for (; r > 0; r = (r & (r + 1)) - 1)
		res += t[num][r];
	return res;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		Set.insert (a[i]);
	}
	
	int cnt = 0;

	for (auto it : Set) {
		++cnt;
		Map[it] = cnt;
	}

	for (int i = 1; i <= n; ++i)
		a[i] = Map[a[i]];

	for (int i = 1; i <= n; ++i) {
	
	}
	
	return 0;
}