#include <bits/stdc++.h>

using namespace std;

const int N = 100;

bool u1[N], u2[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i <= n * n; ++i) {
		int x, y;
		cin >> x >> y;
		if (!u1[x] && !u2[y]) {
			u1[x] = u2[y] = 1;
			cout << i << " ";
		}
	}

	return 0;
}