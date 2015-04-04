#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 200;
const ll bp = 1e9 + 7;

string s;
ll n, k, sum[N];
ll fact[N], rfact[N], pow10[N];

inline ll bin_pow (const ll &base, const ll &power) {
	if (!power)
		return 1;
	if (power & 1)
		return bin_pow (base, power - 1) * base % bp;
	ll b = bin_pow (base, power / 2);
	return b * b % bp;
}

inline ll cnk (const int &n, const int &k) {
	if (k > n)
		return 0;
	return (fact[n] * rfact[k] % bp) * rfact[n - k] % bp;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin); 
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; ++i)
		sum[i] = sum[i - 1] + s[i] - '0';
	fact[0] = 1;
	rfact[0] = 1;
	pow10[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i % bp;
	for (int i = 1; i <= n; ++i)
		rfact[i] = bin_pow (fact[i], bp - 2);
	for (int i = 1; i <= n; ++i)
		pow10[i] = pow10[i - 1] * 10 % bp;
	ll ans = 0;
	if (k == 0) {
		for (int i = 0; i < n; ++i)
			ans = (ans + ((s[i] - '0') * pow10[n - 1 - i])) % bp;
		goto here;
	}
	for (int len = 0; len < n - 1; ++len)
		ans = (ans + ((cnk (n - len - 2, k - 1) * pow10[len] % bp) * sum[n - len - 2])) % bp;
	for (int i = 0; i < n; ++i)
		ans = (ans + (((s[i] - '0') * pow10[n - i - 1] % bp) * cnk (i, k))) % bp;

	here:;	
	cout << ans;
	return 0;
}