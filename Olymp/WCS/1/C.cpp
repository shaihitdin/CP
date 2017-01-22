#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9, bpr = 1e9 + 7;

vector <int> v1, v2;

inline bool check (int x, int base) {
	v1.clear ();
	v2.clear ();
	while (x) {
		v1.emplace_back (x % base);
		x /= base;
	}
	v2 = v1;
	reverse (v2.begin (), v2.end ());
	return v1 == v2;
}

set <int> Set;

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int x;

	cin >> x;
	if (x <= 1e6) {
		for (int i = 2; i < x; ++i)
			if (check (x, i))
				cout << i << " ";
		return 0;
	}	
	for (int i = 2; i <= 1e5; ++i) {
		if (check (x, i)) {
			Set.insert (i);
		}
	}	
	for (int i = 1; i <= 1e5; ++i) {
		if ((x - i) % i == 0 && (x - i) / i > i) {
			Set.insert ((x - i) / i);
		}
	}
	
	for (auto it : Set)
		cout << it << " ";
	
	return 0;
}