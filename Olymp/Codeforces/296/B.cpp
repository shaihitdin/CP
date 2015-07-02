#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 100;

#define F first
#define S second

inline bool cmp (const pii &lhs, const pii &rhs) {
	return lhs.S < rhs.S;
}

pii a[N];

int ans, last;

inline void add (const int &pos) {
	++ans;
	last = pos;
	//cerr << a[pos].F << " " << a[pos].S << "\n";
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x, w;
		cin >> x >> w;
		a[i] = pii (x - w, x + w);
	}

	sort (a + 1, a + n + 1, cmp);
	
	add (1);
	
	for (int i = 2; i <= n; ++i)
		if (a[i].F >= a[last].S)
			add (i);

	cout << ans;
	return 0;
}