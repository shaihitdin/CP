#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	int *s;

	cerr << &s;
	while (1) {
		++s;
		cout << *(s) << " ";
	}
	return 0;
}