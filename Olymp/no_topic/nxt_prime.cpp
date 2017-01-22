#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll n;
int main () {
	cin >> n;
	for (;; ++n) {             	
		bool flag = 1;
		for (ll i = 2; flag && i * i <= n; ++i) {
			if (!(n % i))
				flag = 0;
		}
		if (flag) {
			cout << n;
			return 0;
		}
	}
	return 0;
}