#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "money."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;      
typedef pair <ll, ll> PII;
typedef long double ld;
           
const int N = 2e5;
const int INF = 1e9 + 9;               

int n;
ld a[N], b[N];
ld d[N];

main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	forn(i, 1, n)
		cin >> a[i] >> b[i];
	d[0] = 100000;
	forn(i, 1, n) {
		d[i] = d[i - 1];
		forn(j, 1, i - 1) {                       
			d[i] = max(d[i], d[j] * a[i] / a[j]);
			d[i] = max(d[i], d[j] * b[i] / b[j]);
		}
	}

	cout << fixed << setprecision(10);
	cout << d[n] << "\n";

	return 0;
}
