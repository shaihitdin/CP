#include <iostream>

using namespace std;

int main () {

	double a1, b1, c1, a2, b2, c2;

	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

	double d = a1 * b2 - a2 * b1;

	double x = (c1 * b2 - c2 * b1) / d, y = (a1 * c2 - a2 * c1) / d;

	cout << "The solution is x = " << x << ", y = " << y << endl;

	return 0;
}