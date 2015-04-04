#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
string a1,a2;
int i,m,s;
int main() {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> m >> s;
	if (s == 0 && m != 1) {
		cout << "-1 -1";
		return 0;
	}
	for (i = 1; i <= m; ++i) {
		if (s <= 9) {
			a1 += char('0' + s);
			s = 0;
		}
		else {
			a1 += '9';
			s -= 9;
		}
	}
	if (s != 0) {
		cout << "-1 -1";
		return 0;
	}
	a2 = a1;
	reverse (a1.begin(), a1.end());
	if (a1[0] != '0') {
		cout << a1 << " " << a2;
		return 0;
	}
	int pos = 0;
	for (i = 0; a1[i] == '0' ; ++i);
	if (i == a1.size())	i = 0;
	++a1[pos];
	--a1[i];
	cout << a1 << " " << a2;
	return 0;
}