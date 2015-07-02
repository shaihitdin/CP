#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 1e8 + 1;


int ans;

inline void rec (const ull &till, const ull &pow_ten = 1, const ull &now1 = 0, const ull &now2 = 1) {	
	if (now1 * now2 > till)
		return;
	++ans;
	for (int i = 1; i <= 9; ++i)
		rec (till, pow_ten * 10, now1 + i * pow_ten, now2 * i);
	return;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	rec (10000000000000000);
		
	cout << ans;
	
	return 0;
}