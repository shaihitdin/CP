#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

int d[200];

main () {

	int n;

	cin >> n;

	d[0] = 1;
	d[1] = 2;

	for (int i = 2;; ++i) {
		d[i] = d[i - 1] + d[i - 2];
		if (d[i] > n) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	


	return 0;
}