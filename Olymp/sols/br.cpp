#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

char st[N];
int sz;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	string s;

	cin >> s;

	for (int i = 0; i < s.size (); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st[++sz] = s[i];
		} else {
			if (!sz) {
				cout << "NO";
				return 0;
			}
			if (s[i] == ')' && st[sz] == '(') {
				--sz;
			} else if (s[i] == ']' && st[sz] == '[') {
				--sz;
			} else if (s[i] == '}' && st[sz] == '{') {
				--sz;
			} else {
				cout << "NO";
				return 0;
			}
		}
	}

	if (sz == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}