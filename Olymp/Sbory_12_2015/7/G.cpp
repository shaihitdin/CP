#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

typedef long long ll;


string s;

int z[N];
bool ok[N];
int add[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s;

	for (int i = 1, l = -1, r = -1; i < s.size (); ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < s.size () && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i, r = i + z[i] - 1;
		}
	}
	
	z[0] = s.size ();
	
	for (int i = 0; i < s.size (); ++i) {
		if (i + z[i] == s.size ()) {
			ok[z[i]] = 1;
		}
		++add[z[i]];
	}
	
	
	vector <pair <int, ll> > ans;
	
	ll now = 0;

	for (int i = s.size (); i >= 1; --i) {
		now += add[i];
		if (ok[i])
			ans.emplace_back (make_pair (i, now));
	}
	
	reverse (ans.begin (), ans.end ());

	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it.first << " " << it.second << "\n";
	
	
	return 0;
}