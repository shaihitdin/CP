#include <bits/stdc++.h>

using namespace std;
int n;
int main () {
	int k;
	cin >> k;
	n = 2;
	for (;; ++n) {
		bool flag = 1;
		for (int i = 2; i * i <= n; ++i) {
			if (!(n % i))
				flag = 0;
		}
		if (flag) {
			--k;
			if (k == 0) {
				cout << n;
				return 0;
			}
		}
	}
	return 0;
}