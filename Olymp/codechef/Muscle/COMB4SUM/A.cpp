#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 100;

ll cnt_t[N], sum_t[N];

inline void upd (int pos, const ll &delta, ll t[]) {
	for (; pos < N; pos |= (pos + 1))
		t[pos] += delta;
}

inline ll get (int pos, ll t[]) {
	ll res = 0;
	for (; pos >= 1; pos = (pos & (pos + 1)) - 1)
		res += t[pos];
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> t;

	ull ans = 0;
	
	while (t--) {
		memset (cnt_t, 0, sizeof (cnt_t));
		memset (sum_t, 0, sizeof (sum_t));
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
	
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ull sum1 = get (N - 1, cnt_t) - get (a[i] + a[j], cnt_t), sum2 = get (N - 1, sum_t) - get (a[i] + a[j], sum_t);
				ans += (sum2 - sum1 * (a[i] + a[j])) * 2;
				ull sum1 = get (a[i] + a[j], cnt_t), sum2 = get (a[i] + a[j], sum_t);
				ans += (sum1 * (a[i] + a[j]) - sum2) * 2;
			}
			for (int j = 1; j < i; ++j)
				upd (a[j] + a[i], a[j] + a[i], sum_t), upd (a[j] + a[i], 1, cnt_t);

		}
	}


	return 0;
}