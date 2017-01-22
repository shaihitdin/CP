/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int p;

inline int cnt (int r) {
	return r / p;
}

inline int cnt (int l, int r) {
	return cnt (r) - cnt (l - 1);
}

int l[N], r[N];
long double ans;

inline int calc (int id1, int id2) {
	int x = cnt (l[id1], r[id1]), y = cnt (l[id2], r[id2]);
	double prob = (x * 1.0) / (r[id1] - l[id1] + 1.0);
	double prob2 = (y * 1.0) / (r[id2] - l[id2] + 1.0);
	ans += (prob + prob2 - prob * prob2) * 2000;
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n >> p;
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> r[i];
	for (int i = 1; i < n; ++i) {
		calc (i, i + 1);
	}
	calc (1, n);
	cout << fixed;
	cout.precision (9);
	cout << ans;
	return 0;
}