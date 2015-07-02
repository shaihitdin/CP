#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;


inline int rec (const ull &till, const ull &till2, const ull &pow_ten = 1, const ull &now1 = 0, const ull &now2 = 1) {	
	if (now1 * now2 > till)
		return 0;
	int ans = now1 * now2 <= till && till2 <= now1 * now2;
	for (int i = 1; i <= 9; ++i)
		ans += rec (till, till2, pow_ten * 10, now1 + i * pow_ten, now2 * i);
	return ans;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ull a, b;
	cin >> a >> b;

	cout << rec (b, a);

	return 0;
}