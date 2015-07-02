#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 1e8 + 1;


int ans;

inline void rec (const ull &till, const ull &pow_ten = 1, const ull &now1 = 0, const ull &now2 = 1) {	
	if (now1 * now2 > till)
		return;
	cout << till << " ";
	for (int i = 1; i <= 9; ++i)
		rec (till, pow_ten * 10, now1 + i * pow_ten, now2 * i);
	return;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out1", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	rec (1000000000000);
	
	return 0;
}