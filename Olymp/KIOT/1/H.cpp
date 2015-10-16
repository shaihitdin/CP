#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

inline ll gcd (const ll &a, const ll &b) {
	return b ? gcd (b, a % b) : a;
}

ll a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		ll v;
		cin >> v;
		ll daun = v;
		vector <pair <ll, ll> > primes;
		for (ll i = 2; i * i <= v; ++i) {
			if (v % i == 0) {
				primes.emplace_back (make_pair (1, i));
				while (v % i == 0) {
					primes[primes.size () - 1].first *= i;
					v /= i;
				}
			}
		}
		if (v > 1) {
			primes.emplace_back (make_pair (v, v));
			v = 1;
		}
		ll haha=1;
		for (auto it : primes) {
			bool flag2 = 0;
			ll c = 0;
			for (int i = 1; i <= n; ++i) {
					if (a[i] % it.first == 0) {
						c = gcd (c, a[i]);
					}
				}
			haha = haha / __gcd(haha,c) * c;
		}
		puts (haha == daun?"YES":"NO");
		end:;
	}

	return 0;
}