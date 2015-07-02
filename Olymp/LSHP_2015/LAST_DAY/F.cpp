#include <bits/stdc++.h>

using namespace std;

deque <short> q;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	short n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		short x, s;
		cin >> x;
		if (x == 1) {
			cin >> s;
			q.emplace_front (s);
		}
		if (x == 2) {
			cin >> s;
			q.emplace_back (s);
		}
		if (x == 3) {
			
			if (q.size () == 0) {
				cout << 0 << "\n";
				continue;
			}
			cout << q.front () << "\n";
			//q.pop_front ();
		}
		if (x == 4) {
			if (q.size () == 0) {
				cout << 0 << "\n";
				continue;			
			}
			cout << q.back () << "\n";
			//q.pop_back ();
		}
	}

	return 0;
}