#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map <string,int> mp;
string s;
int n, correct, ans, found, mult;
inline string f (const string &s) {
	char tmp1, tmp2;
	tmp1 = s[0];
	tmp2 = s[s.size() - 1];
	string t = "";
	for (int i = 1; i < (int)s.size() - 1; ++i)
		t += s[i];
	string as = "";
	as += tmp1;
	if (s.size() != 1)
		as += tmp2;
	sort (t.begin(), t.end());
	as += t;
	return as;
}
int main () {
	freopen ("rdeaalbe.in", "r", stdin);
	freopen ("rdeaalbe.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> n;
		mp.clear();
		getline (cin, s);
		cout << "Scenario #" << test << ":\n";
		for (int i = 1; i <= n; ++i) {
			getline (cin, s);
			++mp[f (s)];
		}
		cin >> n;
		getline (cin, s);
		for (int i = 1; i <= n; ++i) {
			getline (cin, s);
			string temp = "";
			ans = 1;
			for (int j = 0; j < s.size(); ++j) {
				while (j < s.size() && s[j] != ' ') {
					temp += s[j];
					++j;
				}
				ans *= mp[f (temp)];
				temp = "";
			}
			cout << ans << "\n";
		}
		cout << "\n";
	}
	return 0;
}