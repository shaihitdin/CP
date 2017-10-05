#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4 + 100, block = 10000;
int b[N * 100 / block + 2][N], b_sum[N * 100 / block + 2][N], a[N * 100];
int tmp[N];

inline void get (int x, int sign) {
	while (x > 0 && x % block != block - 1)
		tmp[a[x--]] += sign;
	if (x == 0)
		return;
	if (sign == -1)
		for (int i = 0; i < N; ++i)
			tmp[i] -= b_sum[x / block][i];
	else
		for (int i = 0; i < N; ++i)
			tmp[i] += b_sum[x / block][i];
}

int main () {

	freopen ("fate.in", "r", stdin);
	freopen ("fate.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		b[i / block][a[i]]++;
		b_sum[i / block][a[i]]++;
	}
	for (int i = 1; i < 110; ++i) {
		for (int j = 0; j < N; ++j) {
			b_sum[i][j] += b_sum[i - 1][j];
		}
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		memset (tmp, 0, sizeof (tmp));
		get (r, +1), get (l - 1, -1);
		ll ans = 0;
		for (int i = N - 1, was = 0; i; --i) {
			ll s_el = tmp[i];
			ll res = (s_el * (s_el + 1)) / 2 * i;
			res += i * 1ll * tmp[i] * was;
			ans += res;
			was += tmp[i];
		}
		cout << ans << "\n";
	}	
	
	return 0;
}