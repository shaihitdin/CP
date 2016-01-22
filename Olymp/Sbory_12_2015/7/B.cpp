#include <bits/stdc++.h>

using namespace std;

bool u[10];
int ans = 0;

inline void get (int i) {
	bool flag = 0;
	while (i) {
		flag |= u[i % 10];
		i /= 10;
	}
	ans += flag;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int tmp = n;
	while (tmp) {
		u[tmp % 10] = 1;
		tmp /= 10;
	}
	
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			get (i);
			if (i * i != n) {
				get (n / i);
			}
		}
	}

	cout << ans;

	return 0;
}