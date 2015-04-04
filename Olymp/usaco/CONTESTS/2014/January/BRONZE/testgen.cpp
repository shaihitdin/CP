#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	freopen ("ccski.in", "w", stdout);
	cout << "500 500\n";
	for (int i = 1; i <= 500; ++i) {
		for (int j = 1; j <= 500; ++j)
			cout << i + j << " ";
		cout << "\n";
	}
	for (int i = 1; i <= 500; ++i) {
		for (int j = 1; j <= 500; ++j)
			cout << 1 << " ";
		cout << "\n";
	}
	return 0;
}