#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int d[N];

int main () {

	int n;
	cin >> n;

	d[0] = 0;

	for (int i = 1; i <= n; ++i) {
		bool u[10];
		memset (u, 0, sizeof (u));
		u[d[i - 1]] = 1;
		if (i % 2 == 0)
			u[0] = 1;
		for (int j = 0;; ++j) {
			if (!u[j]) {
				d[i] = j;
				break;
			}
		}
		cout << i << " " << d[i] << "\n";
	}
	return 0;
}