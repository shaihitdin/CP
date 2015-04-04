#include <iostream>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const short N = 3700;
bitset <N> d[N];
int main () {
	srand (42);
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			d[i][j] = rand() & 1;
	for (int i = 1; i < N; ++i)
		d[i][i] = 1;
	/*
	int k = 1;
	k1:;
		int i = 1;
		i1:;
			int j = 1;
			j1:;
				d[i][j] = (d[i][j] < (c = (d[i][k] + d[k][j]) ) ) ? d[i][j] : c;				
			if (j < N) {
				++j;
				goto j1;
			}
		if (i < N) {
			++i;
			goto i1;
		}
	if (k < N) {
		++k;
		goto k1;
	}
	*/
	for (int k = 1; k < N; ++k)
		for (int i = 1; i < N; ++i)
				if (d[i][k] == 1)
					d[i] |= d[k];
	fprintf (stderr, "%hd", clock() * 1000 / CLOCKS_PER_SEC);
	return 0;
}