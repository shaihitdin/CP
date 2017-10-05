#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

bool u[N];
int n, l; 
vector <int> cycle;
int a[N], b[N];

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

inline int bin_pow (int x, int y, int m) {
	if (y == 0)
		return x;
	if (y & 1)
		return bin_pow (x, y - 1, m) * 1ll * x % m;
	int c = bin_pow (x, y / 2, m);
	return c * 1ll * c % m;
}


inline void dfs (int v) {
	if (u[v]) {
		int m = cycle.size ();
		if (m == 1) {
			a[v] = v;
			return;
		}
		assert (__gcd (l, m) == 1);
		int phi_ = phi (m);
		int shift = bin_pow (l, phi_ - 1, m);
		for (int i = 0; i < m; ++i)
			a[cycle[i]] = cycle[(i + shift) % m];
		return;
	}
	u[v] = 1;
	cycle.push_back (v);
	dfs (b[v]);
	cycle.pop_back ();
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> l;


	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 1; i <= n; ++i) {
		if (!u[i])
			dfs (i);
	}
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";		
	
	return 0;
}