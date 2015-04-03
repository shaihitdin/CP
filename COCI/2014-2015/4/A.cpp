#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
string s;
bool cmp (const char &a, const char &b) {
	return a > b;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin >> s;
	sort (s.begin(), s.end(), cmp);
	if (*s.rbegin() != '0') {
		puts("-1");
		return 0;
	}
	int sum = 0;
	for (auto x : s) {
		sum += (x - '0');
	}
	if (sum % 3 == 0)
		cout << s;
	else
		puts ("-1");
	return 0;
}