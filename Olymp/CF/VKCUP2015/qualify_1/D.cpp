#include <bits/stdc++.h>

using namespace std;

const int N 

struct node {
	int x;
	node *l, *r;
	node () {
		l = r = nullptr;
		x = 0;
	}
	node (node *lhs, node *rhs) {
		x = min (lhs -> x, rhs -> x);
		l = lhs;
		r = rhs;
	}
};

node elements[sz + N];

inline node * Build (const int &v, const int &Tl, const int &Tr) {
	if (Tl == Tr) {
	
	}
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &l, &r);

	}
	return 0;
}