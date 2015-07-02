#include <bits/stdc++.h>

using namespace std;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}


int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	int t;

	scanf ("%d", &t);

	while (t--) {
		int l, r;
		scanf ("%d%d", &l, &r);
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			if (bit (l, i) && l + sum + 1 > r)
				ans |= (1 << i);
			if (!bit (l, i))
				sum |= (1 << i);
		}
		printf ("%d\n", ans);
	}

	return 0;
}