#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
string s, t;
int ans, mp1[256], mp2[256];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> s >> t;
	for (auto it : s)
		++mp1[it];
	for (auto it : t)
		++mp2[it];
	for (int i = 0; i < 256; ++i)
		ans += min (mp1[i], mp2[i]);
	cout << ans;
	return 0;
}