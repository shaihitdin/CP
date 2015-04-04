#include <bits/stdc++.h>

using namespace std;

string s;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	int pref = -1;
	cin >> s;
	char last = s[s.size() - 1];
	for (int j = s.size() - 2; j >= 0; --j) {
		if ((s[j] - '0') % 2 == 0) {
			if (pref == -1 || s[j] < last)
				pref = j;
		}
	}

	if (pref == -1) {
		cout << -1;
		return 0;
	}
	else
		swap (s[s.size() - 1], s[pref]);
	cout << s;
	return 0;
}