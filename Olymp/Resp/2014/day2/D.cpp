#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int N = 100001;
long long ans;
int n, x, y;
struct node {
	int temp, cnt, here;
	node *l, *r;
	node () {
		l = r = NULL;
		temp = here = cnt = 0;
	}
};
int TL;
inline void TLE () {
	if (TL <= clock() * 1000 / CLOCKS_PER_SEC)
    	exit(1);		
}
inline int cnt (node *it) {
	return it ? it -> cnt : 0;
}
inline void upd_cnt (node *&it) {
	if (it) {
		it -> cnt = cnt (it -> l) + cnt (it -> r) + it -> here;
	}
}
inline void upd (node *it, const int &x) {
	if (it && it -> temp) {
		if (it -> temp & (1 << x))
			swap (it -> l, it -> r);
	    if (it -> l)
	    	it -> l -> temp ^= it -> temp;
	    if (it -> r)
	    	it -> r -> temp ^= it -> temp;
	    it -> temp = 0;
	}
}
node *root;
inline void add_node (node *t, const int &x, const int &lvl) {
	upd (t, lvl);
	if (lvl == -1) {
		t -> here += 1;
		upd_cnt (t);
		return;
	}
	if (x & (1 << lvl)) {
		if (!t -> r)
			t -> r = new node();		
		add_node (t -> r, x, lvl - 1);
	}
	else {
		if (!t -> l)
			t -> l = new node();
		add_node (t -> l, x, lvl - 1);	
	}
	upd_cnt (t);
}
inline void move_it (node *t, const int &x, const int &lvl) {
	upd (t, lvl);
	if (!t)	return;
	if (lvl == -1) {
		ans += cnt (t);
		return;
	}
	if (x & (1 << lvl) ) {
		move_it (t -> r, x, lvl - 1);
	}
	else {
		move_it (t -> l, x, lvl - 1);
		ans += cnt (t -> r);
	}
	upd_cnt (t);
}
int main (int argc, char *argv[]) {
	TL = atoi(argv[1]);
	
	freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    root = new node();
    scanf ("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
    	scanf ("%d", &y);
    	root -> temp ^= y;
    	add_node (root, y, 30);
    	move_it (root, x, 30); 
    	TLE();
    }
    printf ("%I64d", ans);
    TLE();
	exit (0);
}