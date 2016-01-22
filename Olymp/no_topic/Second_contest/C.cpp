#include <iostream>

using namespace std;

int main () {

	int a;
	
	cin >> a;

	for (int b = 1; b <= 20; ++b) {
		int ans = 0;
		int x = a + b;
		if (x < 0)
			x = -x;
		for (; x > 0; x = x / 10) {
			if (x % 10 == 8) {
				ans = 1;
			}
		}
		if (ans == 1) {
			cout << b;
			return 0;
		}
	}

}