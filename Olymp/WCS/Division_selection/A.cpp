#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int d[N];
inline int calc (int x) {
	int res = 0;
	while (x) {
		if (x % 10 == 0)
			++res;
		x /= 10;
	}
	return res;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	
	d[0] = 1;
	for (int i = 1; i < N; ++i) {
		d[i] = d[i - 1] + calc (i);
	}

	int t;

	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 0)
			cout << d[b] << "\n";
		else
			cout << d[b] - d[a - 1] << "\n";
	}
	
	return 0;
}