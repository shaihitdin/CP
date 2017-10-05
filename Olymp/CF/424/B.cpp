#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	string s1, s2, s;

	cin >> s1;
	cin >> s2;
	cin >> s;

	for (int i = 0; i < s.size (); ++i) {
		if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))) {
			cout << s[i];		
		}
		for (int j = 0; j < 26; ++j) {
			if (s1[j] == tolower (s[i])) {
				if (s[i] != tolower (s[i])) {
					cout << char (s2[j] - 32);
				} else {
					cout << s2[j];
				}
			}
		}
	}


	return 0;
}