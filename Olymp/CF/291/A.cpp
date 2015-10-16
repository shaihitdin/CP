#include <bits/stdc++.h>

using namespace std;

string s;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0 && s[i] == '9')
			continue;
		s[i] = min (s[i], char ('9' - (s[i] - '0')));
	}
	cout << s;
	return 0;
}