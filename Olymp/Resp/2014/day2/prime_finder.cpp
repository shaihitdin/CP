#include <bits/stdc++.h>

using namespace std;

int cnt;

int main () {

	for (int i = 2; i <= 100; ++i) {
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				--cnt;
				break;
			}
		}
		++cnt;
	}
	cout << cnt;
	return 0;
}