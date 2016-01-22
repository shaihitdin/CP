#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int x;
	
	string s;

	cin >> x;
	cin >> s;
	cin >> s;
	
	if (s == "month") {
		int ans = 0;
		if (x <= 29) {
			ans = 12;
		} else if (x == 30) {
			ans = 11;
		} else {
			ans = 7;
		}
		cout << ans;
	} else {
		int ans = 0;
		if (x == 5 || x == 6)
			ans = 53;
		else
			ans = 52;
		cout << ans;
	}
	
	
	return 0;
}