#include <iostream>
#include <stdio.h>
using namespace std;
int n, t, tp[int(1e5)];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &t);
	for (int i = 1; i < n; ++i)
		scanf ("%d", &tp[i]);
	int i = 1;
	while (i != t && i != n) {
		i = i + tp[i];
	}
	if (i == n && t != n) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}