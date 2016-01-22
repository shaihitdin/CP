#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 100, bpr = 1e9 + 7;

bitset <N> p;
int n;
int ans;

inline int get (const int &x) {
	long long y = x;
	while (y <= n)
		y *= x;
	y /= x;
	return y % bpr;
}


int main () {

	freopen ("lcm.in", "r", stdin);
	freopen ("lcm.out", "w", stdout);
	
	cin >> n;

	for (int i = 2; i < N; i += 2)
		p[i] = 1;

	for (int i = 3; i * i < N; i += 2) {
		if (!p[i])
			for (int j = i * i; j < N; j += i + i)
				p[j] = 1;
	}

	ans = get (2);

	for (int i = 3; i < N; i += 2) {
		if (!p[i])
			ans = (ans * 1ll * get (i)) % bpr;
	}
	
	cout << ans;
	
	return 0;
}