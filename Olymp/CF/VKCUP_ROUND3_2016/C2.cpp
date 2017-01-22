/// izizi

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-6;
const double PI = acos(-1);

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const ll oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100, K = 52;

ll sum[N];
int n, k, a[N];
ld d[N][K];
ld sa[N];
ld sb[N];
int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			d[i][j] = oo;

	d[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
		sa[i] = sa[i - 1] + ld(sum[i]) / a[i];
		sb[i] = sb[i - 1] + ld(1) / a[i];
	}

	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < n; ++i) {
			for (int k2 = i + 1; k2 <= n; ++k2) {
				d[k2][j + 1] = min (d[k2][j + 1], d[i][j] + sa[k2] - sa[i] - ld(sum[i]) * (sb[k2] - sb[i]));
			}
		}
	}

	cout << fixed;
	cout << setprecision (10);

	cout << d[n][k];

	return 0;
}