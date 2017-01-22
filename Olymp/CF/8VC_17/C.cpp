/**
	I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int cnt[N];
int p[N];

inline int get_p (int x) {
	return p[x] = ((p[x] == x) ? x : get_p(p[x]));
}

inline void Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	p[a] = b;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Merge (x, i);
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i)
		ans += (get_p (i) == i);
	
	cout << ans;
	
	return 0;
}