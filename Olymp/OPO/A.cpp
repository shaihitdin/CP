#include <iostream>
#include <stdio.h>
using namespace std;
long long m, k, x, sum;
int main () {
	ios_base :: sync_with_stdio(0);
	cin >> k >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x;
		sum += x;
	}	
	if (sum % k == 0)
		cout << sum / k;
	else
		cout << (sum / k) + 1;
	return 0;
}