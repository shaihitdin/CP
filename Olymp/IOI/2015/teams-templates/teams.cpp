#include "teams.h"
#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 19, N = 1 << 19;

struct node {
	node *l, *r;
	int x;
	node () {
		l = r = 0;
		x = 0;
	}
	node (const int &xx) {
		l = r = 0;
		x = xx;
	}
	node (node *Tl, node *Tr) {
		l = Tl;
		r = Tr;
		x = Tl -> x + Tr -> x;
	}
};

inline int get (node *t, int Tl, int Tr, int l, int r) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline node * upd (node *t, const int &Tl, const int &Tr, const int &x, const int &val) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node (val);
	int mid = (Tl + Tr) >> 1;
	if (x <= mid)
		return new node (upd (t -> l, Tl, mid, x, val), t -> r);
	else
		return new node (t -> l, upd (t -> r, mid + 1, Tr, x, val));
}

inline node * build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node (0);
	int mid = (Tl + Tr) >> 1;
	return new node (build (Tl, mid), build (mid + 1, Tr));
}

int n;
vector <int> g[N];
node *persistent[N];

void init(int N, int A[], int B[]) {
	persistent[0] = build (1, sz);
	n = N;
	for (int i = 0; i < N; ++i)
		g[A[i]].emplace_back (B[i]);
	for (int i = 1; i <= N; ++i) {
		if (i != 1)
			persistent[i] = upd (persistent[i - 1], 1, sz, i - 1, 0);
		else
			persistent[i] = persistent[i - 1];
		for (auto it : g[i])
			persistent[i] = upd (persistent[i], 1, sz, it, get (persistent[i], 1, sz, it, it) + 1);
		g[i].clear ();
	}
}

bool flag = 0;

inline node * walk (node *t, node *used, const int &Tl, const int &Tr, const int &need) {
	if (t -> x - used -> x < need) {
		flag = 1;
		return new node (0);
	}
	if (Tl == Tr)
		return new node (used -> x + need);
	if (!used -> l)
		used -> l = new node (), used -> r = new node ();
	int mid = (Tl + Tr) >> 1;
	if (t -> l -> x - used -> l -> x >= need)
		return new node (walk (t -> l, used -> l, Tl, mid, need), used -> r);
	else
		return new node (t -> l, walk (t -> r, used -> r, mid + 1, Tr, need - (t -> l -> x - used -> l -> x)));
}

inline node * set_zero (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return t;
	if (l <= Tl && Tr <= r)
		return new node ();
	if (!t -> l)
		return t;
	int mid = (Tl + Tr) >> 1;
	return new node (set_zero (t -> l, Tl, mid, l, r), set_zero (t -> r, mid + 1, Tr, l, r));
}

int can (int M, int K[]) {
	node *used;
	used = new node ();
	sort (K, K + M);
	flag = 0;
	int sum = 0;
	for (int i = 0; i < M; ++i) {
		if (K[i] != 1)
			used = set_zero (used, 1, sz, 1, K[i] - 1);
		used = walk (persistent[K[i]], used, 1, sz, K[i]);
		if (flag)
			return 0;
	}
	return 1;
}
