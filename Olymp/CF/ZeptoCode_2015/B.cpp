#include <bits/stdc++.h>

using namespace std;

char a[301];
int n;



int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	nn = (1 << (n + 1)) - 1;

	for (int i = 2; i <= nn; ++i) {
		cin >> a[i];
		mx = max (mx, a[i]);
	}

	while (1) {
		for (int i = nn; i >
	}
	return 0;
}