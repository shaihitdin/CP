#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	cin >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	vector <int> ca, cb;

	for (int i = 1; i <= n; ++i)
		ca.eb (a[i]), cb.eb (b[i]);
	
	sort (ca.begin (), ca.end ()), sort (cb.begin (), cb.end ());
	ca.resize (unique (ca.begin (), ca.end ()) - ca.begin ()), cb.resize (unique (cb.begin (), cb.end ()) - cb.begin ());


	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound (ca.begin (), ca.end (), a[i]) - ca.begin ();
		b[i] = lower_bound (cb.begin (), cb.end (), b[i]) - cb.begin ();
	}	
	
	for (int i = 1; i <= n; ++i) {
		disp[a[i]][b[i]] = 1;
	}
	
	for (int i = 0; i < ca.size (); ++i) {
		int lst = -1;
		for (int j = 0; j < cb.size (); ++j) {
			if (!disp[i][j])
		}
	}
	
	return 0;
}