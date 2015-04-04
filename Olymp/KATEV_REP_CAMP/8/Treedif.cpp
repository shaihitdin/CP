#include <bits/stdc++.h>

using namespace std;

const int N = 100002;

typedef int ll;

const ll inf = 1e9;

struct node {
	ll x, y, mx, mn, cnt;
	node *l, *r;
	node (const ll &element) {
		l = r = 0;
		x = element;
		y = rand();
		mx = element;
		mn = element;
		cnt = 1;
	}
};

vector <ll> g[N];

inline ll cnt (node *it) {
	return it ? it -> cnt : 0;
}

inline void upd (node *it) {
	if (it) {
		it -> mn = (it -> l) ? (it -> l -> mn) : (it -> x);
		it -> mx = (it -> r) ? (it -> r -> mx) : (it -> x);
		it -> cnt = 1 + cnt (it -> l) + cnt (it -> r);
	}
}

inline void Split (node *t, node *&l, node *&r, const ll &key) {
	if (!t)
		l = r = 0;
	else if (t -> x > key)
 		Split (t -> l, l, t -> l, key), r = t;
	else
		Split (t -> r, t -> r, r, key), l = t;
	upd (l); upd (r); upd (t);
}

/*
inline void Merge_two_diff (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y) {
		if (l -> x >= r -> x)
			Merge_two_diff (l -> l, l -> l, r);
		else
			Merge_two_diff (l -> r, l -> r, r);
		t = l;
	}
	else {
		if (r -> x >= l -> x)
			Merge_two_diff (r -> l, l, r -> l);
		else
			Merge_two_diff (r -> r, l, r -> r);
		t = r;	
	}
	upd (l); upd (r); upd (t);
}
*/

inline void Merge (node *&t, node *l, node *r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (l); upd (r); upd (t);
}

ll ans[N];

node *L, *R, *root[N];

inline ll try_other (node *t, node *t2) {
	if (!t)
		return inf;
	ll res = inf;
	ll temp = min (try_other (t -> l, t2), try_other (t -> r, t2));
	if (res > temp)
		res = temp;
	Split (t2, L, R, t -> x);
	if (L && res > (t -> x) - (L -> mx))
		res = (t -> x) - (L -> mx);
	if (R && res > (R -> mn) - (t -> x))
		res = (R -> mn) - (t -> x);
	Merge (t2, L, R);
	return res;
}



inline void Merge_two_diff (node *t, node *to) {
	if (!t)
		return;
	Merge_two_diff (t -> l, to);
	Merge_two_diff (t -> r, to);
	
	t -> l = t -> r = 0;
	
	Split (to, L, R, t -> x);
	Merge (L, L, t);
	Merge (to, L, R);

}

inline void dfs (const ll &v) {
	ans[v] = inf;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		dfs (to);
		ans[v] = min (ans[v], ans[to]);
		if (cnt (root[v]) < cnt (root[to]))
			swap (root[v], root[to]);
		ans[v] = min (ans[v], try_other (root[to], root[v]));				
		Merge_two_diff (root[v], root[to]);
	}
}

int main () {
	srand (time (0));

	ll n, m;
	
	ios_base :: sync_with_stdio (0);

	cin >> n >> m;
	
	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].push_back (i);
	}

	for (int i = n - m + 1; i <= n; ++i) {
		int x;
		cin >> x;
		root[i] = new node (x);
	}
	
	dfs (1);
	
	for (int i = 1; i <= n - m; ++i) {
		if (ans[i] < inf)
			cout << ans[i] << " ";
		else
			cout << INT_MAX << " ";
	}
	return 0;
}
