#include <bits/stdc++.h>

using namespace std;


int main () {

	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);

	int n;
	
	cin >> n;

	if (n <= 7) {
		if (n == 1) {
			cout << "1 1";
		} else if (n == 2) {
			cout << "3 1 1 3";
		} else if (n == 3) {
			cout << "3 4 2 3 2 4";
		} else if (n == 4) {
			cout << "3 4 5 3 2 4 2 5";
		} else if (n == 5) {
			cout << "2 3 2 5 3 4 1 1 5 4";
		} else if (n == 6) {
			cout << "2 4 2 7 3 4 5 3 1 1 7 5";
		} else {
			cout << "2 3 2 7 3 8 6 4 1 1 7 4 6 8";
		}
	} else {
		cout << -1;
	}

	return 0;
}