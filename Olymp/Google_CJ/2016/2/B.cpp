/// Stupido del problemo

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 205;

ld p[N];
ld d[N][N + N];

inline ld calc (vector <ld> a) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N + N; ++j)
			d[i][j] = 0;
	d[0][N] = 1;
	for (int i = 0; i < a.size (); ++i) {
		for (int j = 1; j < N + N; ++j) {
			d[i + 1][j + 1] += d[i][j] * a[i];
			d[i + 1][j - 1] += d[i][j] * (1 - a[i]);
		}
	}
	return d[a.size ()][N];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	cout << fixed;
	cout << setprecision (7);
	
	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> p[i];
		sort (p + 1, p + n + 1);
		ld ans = 0;
		for (int i = 1; i <= n; ++i) {
			vector <ld> cc;
			for (int j = i; j < i + k; ++j)
				cc.eb (p[j]);
			ans = max (ans, calc (cc));
		}
		cout << ans << "\n";
	}
	
	return 0;
}