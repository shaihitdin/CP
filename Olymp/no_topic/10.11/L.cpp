#include <iostream>

using namespace std;

int main () {
	int up = 0, down = 0, maxup = 0, maxdown = 0;
	int x, y = 0;
	while (cin >> x) {
		if (x == 0)
			break;
		if (y == 0) {
			y = x;
			up = 1;
			down = 1;
			maxup = 1;
			maxdown = 1;
			continue;
		}
		if (x > y) {
			up++;
			down = 1;
			maxup = max (maxup, up);
		} else if (x < y) {
			down++;
			up = 1;
			maxdown = max (maxdown, down);
		} else {
			down = 1;
			up = 1;
		}
		y = x;
	}

	cout << max (maxdown, maxup);
	
	return 0;
}