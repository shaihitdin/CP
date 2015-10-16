#include <bits/stdc++.h>

using namespace std;

deque <int> a, b;

int n, k1, k2;
int cnt;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	cin >> n;

	cin >> k1;

	for (int i = 1; i <= k1; ++i) {
		int x;
		cin >> x;
		a.push_front (x);
	}

	cin >> k2;

	for (int i = 1; i <= k2; ++i) {
		int x;
		cin >> x;
		b.push_front (x);
	}	

	for (cnt = 0; cnt < 2e8 && (a.size () && b.size ()); ++cnt) {
		if (a.back () > b.back ()) {
			a.push_front (b.back ());
			a.push_front (a.back ());
		} else {
			b.push_front (a.back ());
			b.push_front (b.back ());		
		}
		a.pop_back ();
		b.pop_back ();
	}

	if (!a.size ()) {
		cout << cnt << " 2\n";
		return 0;
	}
	
	if (!b.size ()) {
		cout << cnt << " 1\n";
		return 0;
	}

	if (cnt == 2e8) {
		cout << "-1\n";
		return 0;
	}

	return 0;
}