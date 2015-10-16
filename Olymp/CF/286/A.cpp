#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string s;
bool flag;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> s;
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
		if (s[i] != s[j]) {
			s = s.substr (0, j + 1) + s[i] + s.substr (j + 1, s.size() - j - 1);
			flag = 1;
			break;
		}
	}
	if (!flag) {
		for (int i = 0; i < s.size() / 2; ++i)
			cout << s[i];
		cout << s[s.size() / 2];
		for (int i = s.size() / 2; i < s.size(); ++i)
			cout << s[i];
		return 0;
	}
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
		if (s[i] != s[j] && flag) {
			cout << "NA";
			return 0;
		}
	}
    cout << s;
    return 0;
}