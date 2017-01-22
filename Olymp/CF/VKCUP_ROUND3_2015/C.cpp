#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int a[N], n;



int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
	
	}

	/*
	for (int i = 1; i <= n * n; ++i) {
		bool flag = 1;
		//cerr << i << "\n";
		for (int j = 1; j <= n; ++j) {
			int x = j;
			for (int k = 1; k <= i; ++k)
				x = a[x];
			int y = x;
			for (int k = 1; k <= i; ++k)
				y = a[y];
			//cerr << j << " " << x << " " << y << " & ";
			if (x != y) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << i;
			return 0;
		}
	}
	*/
	return 0;
}