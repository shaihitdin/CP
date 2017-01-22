#include <iostream>

using namespace std;

int cnk (int n, int k) {
	if (n < 0 || k > n)
		return 0;
	if (k == 0 || n == k)
		return 1;	
	return cnk (n - 1, k) + cnk (n - 1, k - 1);
}


int main () {

	int n, k;

	cin >> n >> k;

	cout << cnk (n, k);

	return 0;
}