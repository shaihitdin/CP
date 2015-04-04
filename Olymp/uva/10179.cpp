#include <iostream>
#include <stdio.h>
using namespace std;
inline long long phi (long long n) {
	long long ans = n;
	for (long long i = 2; i * i <= n; ++i) {
		if ((n % i) == 0) {
			while ((n % i) == 0)
				n /= i;
			ans -= ans / i;
		}
	}
	if (n > 1) ans -= ans / n;
	return ans;
}
long long n;
int main(){
/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
*/
	while(1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		//if (n != 1) {
			cout << phi (n) << "\n";
		//}

		//else {
		//	cout << 0 << "\n";
		//}
	}
	return 0;
}