#include <bits/stdc++.h>

using namespace std;

inline bool prime (int x) {
	if (x == 1)
		return 0;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

int main () {

	int n;

	cin >> n;

	if (prime (n)) {
		cout << 1 << endl;
		return 0;
	}

	if (n % 2 == 0) {
		cout << 2 << endl;
		return 0;
	}
	
	if (n <= 100) {
		for (int i = 2; i < n; ++i) {
			if (prime (i) && prime (n - i)) {
				cout << 2 << endl;
				return 0;
			}
		}
	}
	
	if (prime (n - 2)) {
		cout << 2 << endl;
		return 0;
	}
	
	cout << 3 << endl;
	
	return 0;
}