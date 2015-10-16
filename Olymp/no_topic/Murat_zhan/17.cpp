#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int mx = 1000000, x = 838085;

int main () {


	for (int i = mx; i <= 1500000; ++i)
		if (gcd (i, x) > gcd (mx, x))
			mx = i;
	
	cout << gcd (mx, x);
	
	return 0;
}