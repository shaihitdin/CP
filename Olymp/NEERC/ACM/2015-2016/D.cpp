#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

vector <ll> ans;
ll pw3[60];

inline bool limit (const int &a, const int &b, const ll &c) {
	return (1ll << a) * 1.0 * pw3[b] < c + 100;
}

inline bool rec (const int &pos, const int &a, const ll &cc) {
	if (cc == 0)
		return 1;
	if (pos == 38)
		return 0;
	for (int i = a - 1; i >= 0; --i) {
		if (!limit (i, pos, cc))
			continue;
		if ((1ll << i) * pw3[pos] > cc)
			continue;
		ans.push_back ((1ll << i) * pw3[pos]);
		if (rec (pos + 1, i, cc - ((1ll << i) * pw3[pos])))
			return 1;
		ans.pop_back ();
	}
	if (rec (pos + 1, a, cc))
		return 1;
}

int main () {

	freopen ("distribution.in", "r", stdin);
	freopen ("distribution.out", "w", stdout);

	pw3[0] = 1;

	for (int i = 1; i < 38; ++i)
		pw3[i] = pw3[i - 1] * 3;
	
	int t;
	
	cin >> t;
	
	while (t--) {
		ll n;
		cin >> n;
		ans.clear ();
		rec (0, 60, n);
		cout << ans.size () << "\n";
		for (int i = 0; i < ans.size (); ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}