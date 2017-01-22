#include <iostream>
#include <cstdio>


using namespace std;

int x, k;
int a[100], used[100];

void rec (int n) {
	if (n > x) {
		for (int i = 1; i <= x; ++i) {
			printf ("%d ", a[i]);
		}
		printf ("\n");
		return;
	}
	for (int i = 1; i <= x; ++i) {
		if (used[i] == 0) {
			a[n] = i;
			used[i] = 1;
			rec (n + 1);
			used[i] = 0;
		}
	}
}

int main () {

	scanf ("%d", &x);
	rec (1);

	
	return 0;
}