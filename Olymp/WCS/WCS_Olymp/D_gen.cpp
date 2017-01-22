#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9;

set <int> Set;

inline int RAND () {
	return (rand () * rand ()) % oo;
}

int main () {

	freopen ("in", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	srand (time (0));
	
	int q = 100000;

	cout << q << "\n";

	int cnt = 0;
	
	while (q--) {
		int q_type = RAND () % 3;
		
		if (q_type == 0) {
			while (1) {
				int x = 1 + RAND ();
				if (Set.find (x) == Set.end ()) {
					Set.insert (x);
					cout << "+ " << x << "\n";
					break;
				}
			}
			++cnt;
		} else if (q_type == 1 && cnt) {
			--cnt;
			while (1) {
				int x = 1 + RAND ();
				if (Set.lower_bound (x) != Set.end ()) {
					int sd = *Set.lower_bound (x);
					Set.erase (sd);
					cout << "- " << sd << "\n";
					break;
				}
			}
		} else {
			int k = 1 + (RAND () % 5), d = 1 + RAND ();
			cout << "? " << k << " " << d << "\n";
		}
		if (q % 1000 == 0) {
			cerr << q << "\n";
		}
	}
	
	return 0;
}