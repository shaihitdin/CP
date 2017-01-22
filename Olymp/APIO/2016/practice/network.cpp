#include "network.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int d[N][N];

inline int dist (int i, int j) {
	if (i == j)
		return 0;
	if (d[i][j] != -1)
		return d[i][j];
	return d[i][j] = d[j][i] = ping (i, j) + 1;
}

void findRoute (int n, int a, int b)
{
	memset (d, -1, sizeof (d));
	
	for (int i = a; i != b;) {		
		for (int j = 1; j <= n; ++j) {
			if (dist (j, b) + 1 == dist (i, b) && dist (j, i) == 1) {
				travelTo (j);
				i = j;
				break;
			}
		}
	}
}
