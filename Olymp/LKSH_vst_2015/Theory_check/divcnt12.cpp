#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef ll bg;

vector <ll> primes;

const ll base = 1e9;
const ll inf = 1e18;

bg d[1001][1001], ans;
ll n;

inline bg bin_pow (const bg &a, const bg &b) {
	if (!b)
		return 1;
	if (b & 1)
		return bin_pow (a, b - 1) * a;
	ll git = bin_pow (a, b / 2);
	return git * git;
}

int main () {

	cin >> n;

	for (int i = 2; primes.size () < n; ++i) {
		bool flag = 0;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0)
				flag = 1;
		if (!flag)
			primes.push_back (i);
	}
	
	d[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		ll pr;
		for (int k = 1; k <= min (n, 64LL); ++k) {
			pr = bin_pow (primes[i], bin_pow (2, k) - 1);

			for (int j = i; j + k <= n; ++j) {
				if (!d[i][j])
					continue;
				if (d[i][j] < inf / pr && (!d[i + 1][j + k] || d[i + 1][j + k] > d[i][j] * pr))
					d[i + 1][j + k] = d[i][j] * pr;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		if (!ans || ans > d[i][n])
			ans = d[i][n];
	
	cout << ans;
	
	return 0;
}