#include <bits/stdc++.h>

using namespace std;

inline int sum (int x) {
	int res = 0;
	while (x) {
		res += (x % 10);
		x /= 10;
	}
	return res;
}

int main () {

	freopen ("mcd.in", "r", stdin);
	freopen ("mcd.out", "w", stdout);

	int a, b;

	cin >> a >> b;

	int x = __gcd (a, b);

	int ans = 0, val = 0;
	
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			if (ans < sum (x / i))
				ans = sum (x / i), val = x / i;
			if (ans < sum (i))
				ans = sum (i), val = i;
		}
	}
	
	cout << val;
	
	return 0;
}