/*
ID: shaihit1
PROG: prefix
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

string s[201], t;
int sz, ans;
bool d[200001];

int main() {
	
	freopen ("prefix.in", "r", stdin);
	freopen ("prefix.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	string temp;
	while (1) {
		cin >> temp;
		if (temp == ".")
			break;
		s[++sz] = temp;
	}
	
	while (cin >> temp) {
		t += temp;
	}
	cerr << t << "\n";
	d[0] = 1;
	t = '#' + t;
	for (int i = 0; i < t.size(); ++i)
		for (int j = 1; j <= sz; ++j)
			if (i + s[j].size() < t.size()) 
				d[i + s[j].size()] |= (d[i] && memcmp1 (s[j].c_str(), t.c_str() + i + 1, s[j].size()) == 0);
	
	for (int i = 1; i < t.size(); ++i)
		ans = max (ans, d[i] ? i : 0);
	cout << ans << "\n";
	return 0;
}
