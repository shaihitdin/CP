#include <iostream>
#include <stdio.h>
using namespace std;

int n, x, ans;

int main () {

	freopen ("happy.in", "r", stdin);
	freopen ("happy.out", "w", stdout);
	
	scanf ("%d", &n);
	
	while (n--) {
		scanf ("%d", &x);
		ans += ((x & 1) ? -1 : 1);
	}
	puts ((ans > 0) ? "Happy" : "Sad");
	return 0;
}