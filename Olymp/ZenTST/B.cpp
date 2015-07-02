#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int a[N], n;

inline bool check (const int &pos, const int &l, const int &r) {

	if (pos > n)
		return 1;
		
	int r_begin = r + 1;
	
	for (int i = l; i <= r; ++i) {
		if (a[pos] < a[i]) {
			r_begin = i;
			for (int j = r_begin + 1; j <= r; ++j)
				if (a[pos] > a[j])
					return 0;
			if (!check (r_begin, r_begin, r))
				return 0;
			break;
		}
	}
		
	if (r_begin != pos + 1)
		if (!check (pos + 1, pos + 1, r_begin - 1))
			return 0;
	return 1;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		if (check (1, 1, n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}