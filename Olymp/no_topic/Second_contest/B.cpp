#include <iostream>

using namespace std;

int main () {

	long long n;

	cin >> n;

	long long KAMAZ = 0;
	
	for (long long i = 1; i <= 10000; ++i) {
		long long x = 0;
		for (long long j = 1; j <= i; ++j) {
			x = x + j;
		}
		if (KAMAZ + x > n) {
			cout << i - 1;
			return 0;
		} else {
			KAMAZ = KAMAZ + x;
		}
	}
	
}