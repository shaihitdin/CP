#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;

int sum[N];

pair <int, int> a[N];

inline int get (const int &l, const int &r) {
	return sum[r] - sum[l - 1];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	sort (a + 1, a + n + 1);

	int pos = lower_bound (a + 1, a + n + 1, make_pair (0, 0)) - a;

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i].second;

	int el_cnt = min (pos - 1 - 1 + 1, n - pos + 1);
	
	
	cout << max (get (max (1, pos - 1 - el_cnt + 1 + 1), pos + el_cnt - 1), get (pos - 1 - el_cnt + 1, max (n, pos + el_cnt)));
	
	return 0;
}