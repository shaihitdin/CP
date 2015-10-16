#include <bits/stdc++.h>

using namespace std;

string s, t;

inline bool rec (const int &sl, const int &sr, const int &tl, const int &tr) {
	if (sl == sr)
		return s[sl] == t[tl];
	if ((sr - sl + 1) & 1)
		return !memcmp (&s[sl], &t[tl], sr - sl + 1);
	int smid = (sr + sl) >> 1;
	int tmid = (tr + tl) >> 1;
	if (rec (sl, smid, tl, tmid))
		return rec (smid + 1, sr, tmid + 1, tr);
	if (!rec (sl, smid, tmid + 1, tr))
		return 0;
	return rec (smid + 1, sr, tl, tmid);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> s;
	cin >> t;

	s = "#" + s;
	t = "#" + t;
	
	if (rec (1, s.size () - 1, 1, t.size () - 1))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}