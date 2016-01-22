#include <bits/stdc++.h>

using namespace std;

set <int> Set;

inline void rec (const int &now, const int &sum, const int &now_el) {
	if (now_el == 1) {
		Set.insert (sum + 6 * now);
		return;
	}
	if (now >= now_el)
		rec (now - now_el, sum + (7 - now_el), now_el);
	rec (now, sum, now_el - 1);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;

	n = 30;

	for (int i = 1; i <= n; ++i) {
		rec (i, 0, 6);
		cout << i << " " << Set.size () << "\n";
		Set.clear ();
	}

	return 0;
}