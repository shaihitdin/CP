#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int main () {
	int till;
	cin >> till;
	int n = 2;
	long long res = 1;
	for (; n <= till; ++n) {
		bool flag = 1;
		for (int i = 2; i * i <= n; ++i) {
			if (!(n % i))
				flag = 0;
		}
		if (flag) {
			res *= n;
		}
	}
	
	cout << res;
	return 0;
}