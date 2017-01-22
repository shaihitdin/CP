#include <iostream>

using namespace std;

double Fast_power (double a, int n) {
	double res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res = res * a;
		n /= 2;
		a *= a;
	}
	return res;
}

int main () {

	double a;
	int n;

	cin >> a >> n;

	cout << Fast_power (a, n);

	return 0;
}