#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int a[N];

int main () {

	memset (a, -1, sizeof (a));

	for (int i = 1; i <= 90; ++i)
		a[i] = -1;
	
	a[0] = 0;
	
	for (int i = 1; i <= 90; ++i) {
		for (int j = 1; j <= min (6, i); ++j) {
			if (a[i - j] == 0) {
				a[i] = 1;
			}
		}
		if (a[i] == -1)
			a[i] = 0;
	}
	
		
	cout << a[49] << " " << a[56] << " " << a[85] << " " << a[67] << " " << a[31] << " " << a[42] << " " << a[74];

		
	
	return 0;
}