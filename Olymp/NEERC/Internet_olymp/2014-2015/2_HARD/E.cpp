#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline int solve (const ull &a) {
	if (a == 0)
		return 1;
	int ans = 0;
	for (ull i = 0; i * i * i <= 6 * a; ++i) {
		if ((i * i * i) % 6 != 0) {
			continue;
		}
		ull x = (i * i * i) / 6;
		ull l_bin = 0, r_bin = 32e8;
		while (r_bin - l_bin > 1) {
			ull mid = (r_bin + l_bin) / 2;
			if (mid * mid <= 10 * x)
				l_bin = mid;
			else
				r_bin = mid;
		}
		if (l_bin * l_bin == x * 10)
			++ans;
	}
	return ans;
}

int main () {

	freopen ("exam.in", "r", stdin);
	freopen ("exam.out", "w", stdout);

	ll l, r;
	
	cin >> l >> r;

	if (l > 0)
		cout << solve (r) - solve (l - 1);
	else
		cout << solve (r);
	
	return 0;
}