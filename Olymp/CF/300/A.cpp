#include <bits/stdc++.h>

using namespace std;

string s, t, x;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	s = "CODEFORCES";
	t = s;
	reverse (t.begin (), t.end ());
	cin >> x;
	int i = 0;
	for (; i < x.size () && i < s.size () && x[i] == s[i]; ++i);
	reverse (x.begin (), x.end ());
	int j = 0;
	for (; j < x.size () && j < t.size () && x[j] == t[j]; ++j);
	if (i + j >= 10)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}