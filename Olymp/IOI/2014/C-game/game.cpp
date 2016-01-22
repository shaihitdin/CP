#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1520;

int can[N];
int n;

void initialize(int ns) {	
	n = ns;
	assert (n <= 4);
	for (int i = 0; i < n; ++i)
		can[i] = n - 2;
	can[0] = can[1] = n - 1;
}

int hasEdge(int u, int v) {
    --can[u];
    --can[v];
    if (can[u] <= 0 || can[v] <= 0) {
        return 1;
    } else {
    	return 0;
    }
}