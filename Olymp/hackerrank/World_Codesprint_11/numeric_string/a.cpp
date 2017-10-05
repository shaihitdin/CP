#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

string s;
ll pw[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	ll k, b, m;

	cin >> s >> k >> b >> m;

	for (int i = pw[0] = 1; i < N; ++i)
		pw[i] = pw[i - 1] * b % m;

	ll now = 0;

	for (int i = 0; i + 1 < k; ++i)
		now = (now * b + s[i] - '0') % m;

	ll sum = 0;

	for (int i = k - 1; i < s.size (); ++i) {
		now = (now * b + s[i] - '0') % m;
		if (i - k >= 0)
			now += m - (pw[k] * (s[i - k] - '0')) % m;
		now %= m;
		sum += now;
	}
		

	cout << sum;
		
	return 0;
}