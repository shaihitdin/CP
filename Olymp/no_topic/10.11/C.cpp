#include <iostream>

using namespace std;

int Xor (int a, int b) {
	if (a == true && b == true)
		return 0;
	if (a == false && b == false)
		return 0;
	return 1;
}


int main () {
    int n, m;
	cin >> n >> m;
	cout << Xor (n, m);
	return 0;
}