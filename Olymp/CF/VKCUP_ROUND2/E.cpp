#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int n;

string s, t;

int pref[N], suff[N], ans, first_pos, last_pos;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);

	cin >> n >> s >> t;

	s = "#" + s;
	t = "#" + t;

	
	pref[0] = 1;
	suff[n + 1] = 1;

	first_pos = n;
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] == t[i])
			pref[i] = pref[i - 1];
		else {
			first_pos = min (first_pos, i);
			pref[i] = 0;
		}
	}
	last_pos = 1;
	for (int i = n; i; --i) {
		if (s[i] == t[i])
			suff[i] = suff[i + 1];
		else {
			last_pos = max (last_pos, i);
			suff[i] = 0;
		}
	}

	cerr << (s.substr (0, first_pos) + s[first_pos] + t[first_pos] + s.substr (first_pos + 1)) << " == " << (t.substr (0, last_pos) + s[last_pos] + t.substr (last_pos)) << "\n";

	cerr << (s.substr (0, last_pos) + s[last_pos] + t[last_pos] + s.substr (last_pos + 1)) << " == " << 	(t.substr (0, first_pos) + s[first_pos] + t.substr (first_pos)) << "\n";
	
	ans = ((s.substr (0, first_pos) + t[first_pos] + s[first_pos] + s.substr (first_pos + 1)) == (t.substr (0, last_pos) + s[last_pos] + t.substr (last_pos))) 
	+
	 ((s.substr (0, last_pos) + s[last_pos] + t[last_pos] + s.substr (last_pos + 1)) == (t.substr (0, first_pos) + s[first_pos] + t.substr (first_pos)));
	cout << ans;
	
	return 0;
}