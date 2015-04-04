#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;
map <string, string> mp;
string x[3001], y[3001], a;
int n, m;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		mp[x[i]] = y[i];
		mp[y[i]] = x[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (!mp[a].size() && mp[a].size() < a.size())
			cout << mp[a] << " ";
		else
			cout << a << " ";
	}
	return 0;
}