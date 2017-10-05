#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100, C = 1e5;

int d[N], stq, enq, st[N];
vector <int> a;

inline bool inside (int x) {
	return 0 <= x && x < N;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int m, k;
	cin >> m >> k;

	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		x -= m;
		if (!d[C + x]) {
			d[C + x] = 1;
			st[++enq] = C + x;
			a.push_back (x);
		}
		
	}

	while (stq != enq) {
		int v = st[++stq];
		for (auto it : a) {
			if (inside (v + it) && !d[v + it]) {
				d[v + it] = d[v] + 1;
				st[++enq] = v + it;
			}
		}
	}
	
	if (!d[C]) {
		cout << -1 << "\n";
	} else {
		cout << d[C] << "\n";
	}
	
	return 0;
}