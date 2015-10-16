#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5010;
const ll oo = 1e18;

ll d[N], p[N], a[N], h[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	
	d[1] = a[1];
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (p[i] > p[j]) {
				d[i] = min (d[i], (-2 * h[i] * h[j]) + (d[j] + h[j] * h[j]));
			}
		}
		d[i] += a[i] + h[i] * h[i];
	}
	
	/// d[i] = (min j < i (d[j] + (h[i] - h[j]) ^ 2)) + a[i] 
	
	/// ==> (min j < i (d[j] + h[i] ^ 2 + h[j] ^ 2 - 2 * h[i] * h[j])) + a[i]

	/// ==> (min j < i (- (2 * h[j] * h[i]) + (d[j] + h[j] ^ 2))) + a[i] + h[i] ^ 2

	/// ==> (min j < i (- (ax) + b)) + a[i] + h[i] ^ 2, where a = -2 * h[j] and b = d[j] + h[j] ^ 2
	
	cout << d[n];
	
	return 0;
}