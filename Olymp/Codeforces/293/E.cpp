#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 20;

int n, k;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n >> k;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		if (s[0] == '?')
			f[i] = 1;
		else
			a[i] = stoi (s);
	}
	last[n + 1] = n + 1;
	for (int i = n; i; --i) {
		if (f[i])
			last[i] = i;
		else
			last[i] = last[i + 1];
	}
	
	return 0;
}