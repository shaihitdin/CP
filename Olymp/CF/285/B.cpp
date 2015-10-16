#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
#define mkp make_pair
#define F first
#define S second
map <string, string> m1;
string a, b;
int q;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> a >> b;
		if (m1[a].size() == 0)
			m1[a] = a;
		bool flag = 1;
		if (m1[a] == a)
			flag = 0;
		m1[m1[a]] = b;
		if (flag)
			m1.erase (a);
	}
	cout << m1.size() << "\n";
	for (auto it : m1)
		cout << it.F << " " << it.S << "\n";
	return 0;
}