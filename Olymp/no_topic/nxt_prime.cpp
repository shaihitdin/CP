#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int main () {
	cin >> n;
	for (;; ++n) {
		bool flag = 1;
		for (int i = 2; i * i <= n; ++i) {
			if (!(n % i))
				flag = 0;
		}
		if (flag) {
			cout << n;
			return 0;
		}
	}
	return 0;
}