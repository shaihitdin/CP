#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m;
string op[N];
int b[32];
int a[N];


inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline int result (int x) {
	int saved = x;
	for (int i = 1; i <= n; ++i) {
		if (op[i] == "AND")
			x &= a[i];
		else if (op[i] == "OR")
			x |= a[i];
		else
			x ^= a[i];
		x &= saved;
	}
	return x;
}

inline int result2 (int x) {
	for (int i = 1; i <= n; ++i) {
		if (op[i] == "AND")
			x &= a[i];
		else if (op[i] == "OR")
			x |= a[i];
		else
			x ^= a[i];
	}
	return x;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> op[i] >> a[i];
	}

	for (int i = 29; i >= 0; --i) {
		int x = (1 << i);
		b[i] = result (x);
	}
	
	b[30] = result2 (0);
	int ans = 0;

	bool flag = 1;
	
	for (int i = 29; i >= 0; --i) {
		if (flag) {
			if (bit (m, i)) {
				if (bit (b[30], i))
					flag = 0;
				else if (bit (b[i], i))
					ans |= (1 << i);
				else
					flag = 0;
			} else {
				continue;
			}
		} else {
			if (bit (b[30], i))
				continue;
			else if (bit (b[i], i))
				ans |= (1 << i);
		}
	}
	
	cout << result2 (ans);
	
	return 0;
}