#include <iostream>

using namespace std;

int main () {

	int prevprev = 0, prev = 0, x, ans = 100000, position = 0, i = 0;
	
	
	while (cin >> x) {
		i++;
		if (x == 0)
			break;
		if (prev == 0) {
			prev = x;
			continue;
		}
		if (prevprev == 0) {
			prevprev = prev;
			prev = x;
			continue;
		}
		if (prev > prevprev && prev > x) {
			if (position != 0)
				ans = min (ans, i - 1 - position);
			position = i - 1;
		}
		prevprev = prev;
		prev = x;
	}

	if (ans == 100000)
		cout << 0;
	else
		cout << ans;
	
	return 0;
}