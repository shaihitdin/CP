#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 200, C = 18;

ll b[N][C];
int lg[N];

inline ll gcd (const ll &a, const ll &b) {
	return b ? gcd (b, a % b) : a;
}

inline ll get (const int &l, const int &r) {
	int d = r - l + 1;
	return gcd (b[l][lg[d]], b[r - (1 << lg[d]) + 1][lg[d]]);
}

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;

	cin >> t;

	for (int i = 2; i < N; ++i)
		lg[i] = lg[i / 2] + 1;
	
	
	while (t--) {
		
		int n;
		
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> b[i][0];

			
		for (int i = 1; i < C; ++i) {
			for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
				b[j][i] = gcd (b[j][i - 1], b[j + (1 << (i - 1))][i - 1]);
			}
		}
	
		ll ans = -1;
		
		for (int i = 1; i <= n; ++i) {
			int j = i;
			while (j >= 1) {
				ll now = get (j, i);
				int l = 0, r = j;
				while (r - l > 1) {
					int mid = (r + l) >> 1;
					if (get (mid, i) == now)
						r = mid;
					else
						l = mid;
				}
				ans = max (ans, now * (i - r + 1));
				j = l;
			}
		}
		cout << ans << "\n";
	}	


	return 0;
}