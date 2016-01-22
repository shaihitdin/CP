#include <bits/stdc++.h>

using namespace std;

const int N = 7e5 + 100, bpr = 1e9 + 7;

typedef long long ll;

ll f[N], f_rev[N];

inline ll bin_pow (ll a, int b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % bpr;
		a = (a * a) % bpr, b >>= 1;	
	}
	return res;                
}

inline ll cnk (const ll &n, const ll &k) {
	return (((f[n] * f_rev[k]) % bpr) * f_rev[n - k]) % bpr;
}

ll cat(int n) {
 	return (cnk (2 * n, n) * bin_pow(n + 1, bpr - 2)) % bpr;
}

ll r(ll x) {
	return bin_pow(x, bpr - 2);
}

ll trees(int n) {                                 /*
	ll dv = (((r(f[n]) * r(f[n + 1])) % bpr) * r(f[n + 2])) % bpr;
	return (((2 * f[3 * n]) % bpr) * dv) % bpr; */
	return (cnk(4 * n + 2, 2 * n + 1) * r(2 * n + 2)) % bpr;
}

int main () {

	freopen ("bracetree.in", "r", stdin);
	freopen ("bracetree.out", "w", stdout);

	ll n;	
	
	cin >> n;

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;

	for (int i = 0; i < N; ++i)
		f_rev[i] = bin_pow (f[i], bpr - 2);

	for (int i = 0; i < 5; ++i)
		cerr << trees(i) << "\n";

	for (int i = 0; i < 5; ++i)
		cerr << cat (i) << " ";
	
	cout << (trees (n - 1) * cat(n)) % bpr;

	return 0;
}
