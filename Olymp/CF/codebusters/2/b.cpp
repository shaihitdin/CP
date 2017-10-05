#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll pw[22];
ll pre[(1 << 18)][100], nx[(1 << 18)][100];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	ll n, m;
	cin >> n >> m;
	int len = 0;
	while (n) {
		++cnt[n % 10];
		n /= 10;
		++len;
	}
	for (int i = pw[0] = 1; i < len; ++i) {
		pw[i] = pw[i - 1] * 10;
	}
	
	
	nx[0][0] = 1;
	
	
	for (int i = 9; i >= 1; --i) {
		while (cnt[i]--) {
			memcpy (pre, nx, sizeof (nx));
			memset (nx, 0, sizeof (nx));
			for (int mask = (1 << len) - 1; mask >= 0; --mask) {
				for (int j = 0; j < len; ++j) {
					if ((mask >> j) & 1)
						continue;
					for (int dd = 0; dd < m; ++dd) {
						nx[mask | (1 << j)][(dd + pw[j] * i) % m] += pre[mask][dd];
					}
				}
			}
		}
	}	
	return 0;
}