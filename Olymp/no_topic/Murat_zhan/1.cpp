#include <bits/stdc++.h>

using namespace std;

int main () {

	string s;

	while (cin >> s) {
		reverse (s.begin (), s.end ());
		int ans = 0;
		for (int i = 0; i < s.size (); ++i) {
			ans += ((1 << i) * (s[i] - '0'));
		}
		cout << char (ans) << "\n";
	}
	
	return 0;
}