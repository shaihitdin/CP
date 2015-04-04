#include <iostream>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
long long rndm[100501];

struct node {
	long long x, y, add, start, stop_new, ans;
	node *l, *r;
	node () {
		x = y = add = start = stop_new = ans = 0;
		l = r = NULL;
	}
};

node *root, *L, *R, *R1, *mid, *tmp;
long long dist;
long long d[100501];
long long n, xx[100501], go[100501], ene[100501], i;

long long ans (node *&it) {
	return it? d[i] - d[(it -> start) - 1] : -1;
}

long long g_ans (node *&it) {
	if (it) {
		it -> ans = max (d[i] - d[(it -> start) - 1], max (ans (it -> l), ans (it -> r) ) );
	}
}

void upd (node *&it) {
	if (it && it -> add) {
		it -> x += it -> add;
		if (it -> l)
			it -> l -> add += it -> add;
		if (it -> r)
			it -> r -> add += it -> add;
		it -> add = 0;		
	}
}
void Merge (node *&t, node *l, node *r) {
	upd(l); upd(r); upd(t);
	g_ans (l); g_ans (r); g_ans (t);
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else 
		Merge (r -> l, l, r -> l), t = r;
	upd(t); upd(l); upd(r);	
	g_ans (l); g_ans (r); g_ans (t);

}

void Split (node *t, node *&l, node *&r, long long Split_key) {
	upd(t); upd(l); upd(r);
	g_ans (l); g_ans (r); g_ans (t);

	if (!t) {
		l = r = 0;
		return;
	}
	if (t -> x >= Split_key)
		Split (t -> l, l, t -> l, Split_key), r = t;
	else
		Split (t -> r, t -> r, r, Split_key), l = t;
	upd(l); upd(r); upd(t);
	g_ans (l); g_ans (r); g_ans (t);

}
/*
void get_ans (node *it) {
	if (!it)
		return;
	upd (it);
	get_ans (it -> l);
	dist = max (dist, d[it -> stop] - d[(it -> start) - 1]);
	get_ans (it -> r);
}
*/
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> n;
	srand (time (0));
	for (i = 1; i <= 100500; ++i)
		rndm[i] = i;
	random_shuffle (rndm + 1, rndm + 1 + 100500); 
	for (i = 1; i <= n; ++i) {
		cin >> xx[i] >> go[i] >> ene[i];
		d[i] = d[i - 1] + go[i];
		Split (root, L, R, xx[i] - ene[i]);
		if (R)
			dist = max (dist, R -> ans);
		Merge (root, L, R);
		tmp = new node();
		tmp -> x = xx[i] + ene[i];
		tmp -> y = rndm[i];
		tmp -> start = i;
		Split (root, L, R, xx[i] + ene[i]);
		Merge (R, tmp, R);
		Merge (root, L, R);
	}
	cout << dist;
	return 0;
}