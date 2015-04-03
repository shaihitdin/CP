#include <bits/stdc++.h>

using namespace std;

int n, o[11], v[11], dd[11], m;
string s[23];

inline bool rec (const char &num, const char &def, const char &mid, const char &att) {
	if (num == m + 1)
		return def == 0 && mid == 0 && att == 0;

	for (char i = 0; i < s[num].size(); ++i) {
		if (s[num][i] == 'O' && def && rec (num + 1, def - 1, mid, att))
			return 1;
		else if (s[num][i] == 'V' && mid && rec (num + 1, def, mid - 1, att))
			return 1;
		else if (s[num][i] == 'N' && att && rec (num + 1, def, mid, att - 1))
			return 1;
	}
	return rec (num + 1, def, mid, att);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d-%d-%d", &o[i], &v[i], &dd[i]);
	}
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i)
		cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		if (rec (1, o[i], v[i], dd[i]))
			puts ("DA");
		else 
			puts ("NE");
	}	
	return 0;
}