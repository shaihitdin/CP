#include <iostream>
#include <stdio.h>
using namespace std;
const long double eps = 0.000001;
long double a1, b1, a2, b2, a, b, c, d;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> a >> b >> c >> d;
	a1 = c;
	b1 = b / (a / c);
	b2 = d;
	a2 = a / (b / d);
	if (b1 > d + eps) {
		cout << int (a2) << " " << int (b2);
		return 0;
	}
	if (a2 > c + eps) {
		cout << int (a1) << " " << int (b1);
		return 0;
	}
	if (a1 * b1 > a2 * b2) {
		cout << int (a1) << " " << int (b1);
		return 0;
	}
	else {
		cout << int (a2) << " " << int (b2);
		return 0;
	} 
	return 0;
} 