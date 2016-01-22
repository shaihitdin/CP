#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (ll i = ll(x); i <= ll(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "lcm."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;

const int N = 2e6;

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int t;
ll a, b;

const int C = 20;

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	forn(_, 1, t) {
		cin >> a >> b;
		ll ans = lcm(a, b);
		forn(i, max(1ll, b - C), b)
			ans = max(ans, lcm(a, i));		
		cout << ans << "\n";
	}

	return 0;             
}       