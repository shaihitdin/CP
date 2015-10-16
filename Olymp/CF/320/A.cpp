#include <bits/stdc++.h>

using namespace std;

const int N = 1e5, oo = 1e9;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int x;
	
	cin >> x;
	
	cout << __builtin_popcount (x);
	
	return 0;
}