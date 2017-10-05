#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

inline int find_cb (int x) {
	int l = 0, r = 1e6 + 10;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (mid * mid * mid <= x)
			l = mid;
	   	else
	   		r = mid;
	}
	if (l * l * l != x)
		return -1;
	return l;
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;	
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a * b == 1) {
			cout << "Yes\n";
			continue;
		}
		int c = a * b;
		c = find_cb (c);
		if (c == -1) {
			cout << "No\n";
			continue;
		}
		if (a % c != 0 || b % c != 0) {
			cout << "No\n";
			continue;
		}
		a /= c;
		b /= c;
		if (a * b == c)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}