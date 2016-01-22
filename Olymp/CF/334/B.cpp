#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int bpr = 1e9 + 7;

const int N = 1e6 + 100;

int fixed_p;

ll ans = 1, p, k;

bool u[N];
int res[N];

inline void dfs (const int &v, const int &cnt) {
	if (u[v]) {
		++res[cnt];
		return;
	}
	u[v] = 1;
	dfs ((v * k) % p, cnt + 1);
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> p >> k;

	if (k == 0) {
		for (int i = 1; i < p; ++i)
			ans = (ans * p) % bpr;
		cout << ans;
		return 0;
	}
	
	for (int i = 1; i < p; ++i)
		if (!u[i])
			dfs (i, 0);
	
	for (int i = 1; i < p; ++i) {
		for (int j = 1; j <= res[i]; ++j) {
			ll tmp = i * 1ll * res[i];
			++tmp;
			tmp %= bpr;
			ans = (ans * tmp) % bpr;
		}
	}
	
	cout << ans;

	return 0;
}