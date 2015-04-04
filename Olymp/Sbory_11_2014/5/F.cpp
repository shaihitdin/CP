#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

string s;
int c[256];
int c1[256];
int d[100001];
int d1[100001];
int ans;
int main () {
	freopen ("mountain.in", "r", stdin);
	freopen ("mountain.out" ,"w", stdout);
	cin >> s;
	ans = s.size() + 100;
	for (int i = 0; i < s.size(); ++i) {
		for (char j = '0'; j <= s[i]; ++j) {
			d[i] = max (d[i], c[j] + 1);
		}
		c[s[i]] = max (c[s[i]], d[i]);
	}
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		for (char j = '9'; j >= s[i]; --j) {
			d1[i] = max (d1[i], c1[j] + 1);
		}
		c1[s[i]] = max (c1[s[i]], d1[i]);
	}
	for (int i = 0; i < s.size(); ++i) {
		cerr << i << " " << d[i] << " " << d1[i] << "\n";
		ans = min (ans, (i + 1) - d[i] + ( ( int (s.size()) - 1) - d1[i]) + 1);
	}
	cout << ans;
	return 0;
}