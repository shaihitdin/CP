#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, y, cnt;
	node *l, *r;
	node (const int &el) {
		x = el;
		y = rand();
		l = r = 0;
	}
}

inline int cnt (node *&it) {
	return it ? it -> cnt : 0;
}

inline void upd (node *&it) {
	if (it) {
		it -> cnt = cnt (it -> l) + cnt (it -> r) + 1;
	}
}

inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
 	else
 		Merge (r -> l, l, r -> l), t = r;
 	upd (t);
}
int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	return 0;
}