#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s;
	for (int i = 0; i < s.size (); ++i) {
		for (int j = i + 1; j < s.size (); ++j) {
			if (s[i] == s[j]) {
				int len = j - i + 1;
				pt1 = i;
				pt2 = j;
				if (abs (i - j) == 1) {
					cout << "Impossible";
					return 0;
				}
			}
		}
	}
	for (int i = len / 2 - 1; i >= 0; --i) {
		a[0][i] = s[pt1++];
	}
	for (int i = 0; pt1 <= pt2; ++i) {
		a[1][i] = s[pt1++];
	}
	
	for (itn i = 1;
	
	return 0;
}