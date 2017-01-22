#include <iostream>

using namespace std;

double power (double a, int n) {
	double b = 1;
	for (int i = 1; i <= n; ++i, b = b * a);
	return b;
}

int main () {

	double a, b;

	cin >> a >> b;
	cout << power (a, b);

	return 0;
}