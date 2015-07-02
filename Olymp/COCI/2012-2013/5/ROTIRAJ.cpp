#include <bits/stdc++.h>

using namespace std;

int rndm[N];

inline int myrand (const int &r) {
	return (((rand () * 1ll ) << 14) + rand ()) % r;
}

struct node {
	int x, y, cnt;
	node *l, *r;
	node () {
		x = y = cnt = b_num = 0;
		l = r = nullptr;
	}
	node (const int &element) {
		
	}
}


int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	srand (time (0));

	for (int i = 1; i < N; ++i)
		rnd[i] = i;

	random_shuffle (rnd + 1, rnd + N, myrand);
		
	scanf ("%d%d%d", &n, &k, &q);

	for (int i = 1; i <= q; ++i) {
	
	}

	return 0;
}