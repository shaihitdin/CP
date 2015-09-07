#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100;

int cnt[N][26];

inline int gcd (const ll &x, const ll &y) {
	return (y ? gcd (y, x % y) : x);
}

ll n, m;
string x, y;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	cin >> x >> y;

	if (n < m) {
		swap (n, m);
		swap (x, y);
	}

	ll g = gcd (x.size (), y.size ());
	
	for (int i = 0; i < y.size (); ++i) {
		++cnt[i % g][y[i] - 'a'];
	}
	
	ll ans = 0;
	for (int i = 0; i < x.size (); ++i) {
		ans += cnt[i % g][x[i] - 'a'];
	}
	
	cout << (n * x.size ()) - ans * ((n * x.size ()) / (x.size () / g * y.size ()));
	
	return 0;
}