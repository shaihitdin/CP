/*
ID: shaihit1
PROG: contact
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, n;
string s, t;

map <int, vector <string> > Map1;
map <string, int> Map;

inline bool cmp (const string &x, const string &y) {
	if (x.size() == y.size())
		return x < y;
	return x.size() < y.size();
}
int main() {
	
	freopen ("contact.in", "r", stdin);
	freopen ("contact.out", "w", stdout);

	cin >> a >> b >> n;
	while (cin >> t) {
		s += t;
	}
	for (int i = 0; i < s.size(); ++i)
		for (int j = a; j <= b && i + j <= s.size(); ++j)
			++Map[s.substr (i, j)];
	for (auto it : Map)
		Map1[it.second].push_back (it.first);
	for (auto it = Map1.rbegin(); --n >= 0 && it != Map1.rend(); ++it) {
		sort (it -> second.begin(), it -> second.end(), cmp);
		cout << it -> first << "\n";
		int cnt = 0;
		for (auto it1 : it -> second) {
			if ((cnt && cnt % 6 == 5) || (cnt + 1 == it -> second.size()))
				cout << it1 << '\n';
			else
				cout << it1 << " ";
			++cnt;
		}
	}
	return 0;
}
