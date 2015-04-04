#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int N = 1006, mod = (1e9) + 1;
typedef long long ll;
const ll inf = 1e15;
int n, m;
char tn[N];
inline int grand() {
	return (rand() << 15) ^ rand();
}
int main () {
	srand (7777777);
	int test = 1;
	sprintf (tn, "%.02d", test);
	freopen (tn, "w", stdout);
	n = 2;
	m = 3;
	printf ("%d %d\n", n, m);
	printf ("2 2 3\n3 2 1");
	fclose (stdout);
	test = 2;
	for (; test <= 3; ++test) {
		sprintf (tn, "%.02d", test);
		freopen (tn, "w", stdout);
		n = 1000;
		m = 10;
		printf ("%d %d\n", n, m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf ("%d ", 1 + (grand() % mod));
			}
			printf ("\n");
		}
		fclose (stdout);		
	}
	for (; test <= 6; ++test) {
		sprintf (tn, "%.02d", test);
		freopen (tn, "w", stdout);
		n = 1000;
		m = 100;
		printf ("%d %d\n", n, m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf ("%d ", 1 + (grand() % mod));
			}
			printf ("\n");
		}
		fclose (stdout);		
	}

	for (; test <= 10; ++test) {
		sprintf (tn, "%.02d", test);
		freopen (tn, "w", stdout);
		n = 1000;
		m = 1000;
		printf ("%d %d\n", n, m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf ("%d ", 1 + (grand() % mod));
			}
			printf ("\n");
		}
		fclose (stdout);		
	}	
	
	return 0;
}