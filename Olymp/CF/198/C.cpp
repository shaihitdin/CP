#include <bits/stdc++.h>

using namespace std;

const int N = 2050, bpr = 1e9 + 7;

int f[N], Cnk[N][N], cnt, cnt2, n;

bool u[N];

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	f[0] = 1;
	
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	
	for (int i = 0; i < N; ++i) {
		Cnk[i][i] = Cnk[i][0] = 1;
		for (int j = 1; j < i; ++j)
			Cnk[i][j] = (Cnk[i - 1][j - 1] + Cnk[i - 1][j]) % bpr;
	}
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != -1) {
			u[a[i]] = 1;
			++cnt;
		}
	}

	for (int i = 1; i <= n; ++i)
		cnt2 += (a[i] == -1 && !u[i]);
	
	int can = n - cnt;
	
	int ans = 0;
	
	for (int i = 0; i <= cnt2; ++i) {
		int tmp = (Cnk[cnt2][i] * 1ll * f[can - i]) % bpr;
		if (i & 1)
			ans -= tmp;
		else
			ans += tmp;
		ans %= bpr;
		ans += bpr;
		ans %= bpr;
	}
	
	cout << ans;
	return 0;
}