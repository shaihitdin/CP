#include <bits/stdc++.h>

using namespace std;

int main () {

	int a = 24149, b = 4328423;
	int *c, *d;

	d = &b;
	c = *&d;
	*c = 555;

	cout << *d << " " << *c;

	return 0;
}