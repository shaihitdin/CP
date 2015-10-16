#include <bits/stdc++.h>

using namespace std;

int n, m, a1, a2;

int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m >> a1 >> a2;
	if (n <= m)
		cout << "Second";
	else
		cout << "First";

	return 0;
}