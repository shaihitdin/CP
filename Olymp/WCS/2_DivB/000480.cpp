#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 100;

struct node {
	int x, y, cnt;
	node *l, *r, *p;
	bool flag, cycle;
	node() {
		x = 0;
		cnt = 1;
		y = rand ();
		l = r = p = 0;
		flag = cycle = 0;
	}
	node(const int &key) {
		x = key;
		cnt = 1;
		y = rand ();
		l = r = p = 0;
		flag = cycle = 0;
	}
};

inline void push(node *t) {
	if (t && t -> flag) {
		swap (t -> l, t -> r);
		t -> flag = 0;
		if (t -> l)
			t -> l -> flag ^= 1;
		if (t -> r)
			t -> r -> flag ^= 1;
	}
}

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline void upd(node *it) {
	if (it) {
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
		if (it -> l)
			it -> l -> p = it;
		if (it -> r)
			it -> r -> p = it;
	}
}

inline void Merge(node *&t, node *l, node *r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge(l -> r, l -> r, r), t = l;
	else
		Merge(r -> l, l, r -> l), t = r;
	upd(t);
}

inline void Split_cnt(node *t, node *&l, node *&r, const int &x) {
	push (t);
	if (!t) {
		l = r = 0;
		return;
	}
	if (cnt(t -> l) + 1 > x)
		Split_cnt(t -> l, l, t -> l, x), r = t;
	else
		Split_cnt(t -> r, t -> r, r, x - cnt(t -> l) - 1), l = t;
	if (l)
		l -> p = nullptr;
	if (r)
		r -> p = nullptr;
	upd(l);
	upd(r);
}

ll ans;

node *root[N], *L[5], *R[5];

inline int get_first (node *t) {
	if (t -> l)
		return get_first (t -> l);
	push (t);
	return t -> x;
}

inline int get_last (node *t) {
	if (t -> r)
		return get_last (t -> r);
	push (t);
	return t -> x;
}

inline int get_root (int x) {
	node *tmp = root[x];
	while (tmp -> p)
		tmp = tmp -> p;
	return tmp -> x;
}

inline int pos_in_treap (int x) {
	node *tmp = root[x];
	vector <node*> aba;
	while (tmp -> p) {
		aba.emplace_back (tmp);
		tmp = tmp -> p;
	}
	aba.emplace_back (tmp);
	reverse (aba.begin (), aba.end ());
	for (int i = 0; i < aba.size (); ++i)
		push (aba[i]);
	int res = 0;
	for (int i = 0; i + 1 < aba.size (); ++i)
		if (aba[i] -> r == aba[i + 1])
			res += cnt (aba[i] -> l);
	res += cnt (aba[aba.size () - 1] -> l) + 1;
	return res;
}

inline void add_edge (int x, int y) {
	if (x > y)
		swap (x, y);
	if (get_root (x) == get_root (y)) {
		node *tmp = root[get_root (x)];
		tmp -> cycle = 1;
	} else {
		node *tmp1 = root[x], *tmp2 = root[y];
		bool flag1 = get_first (tmp1) == x, flag2 = get_first (tmp2) == y;
		if (flag1 == 0 && flag2 == 0) {
			tmp1 -> flag ^= 1;
			Merge (tmp2, tmp2, tmp1);
		} else if (flag1 == 0 && flag2 == 1) {
			Merge (tmp1, tmp1, tmp2);
		} else if (flag1 == 1 && flag2 == 0) {
			Merge (tmp2, tmp2, tmp1);
		} else {
			tmp1 -> flag ^= 1;
			Merge (tmp1, tmp1, tmp2);
		}
	}
}

inline void del_edge (int x, int y) {
	if (x > y)
		swap (x, y);
	if (root[get_root (x)] -> cycle) {
		node *tmp = root[get_root (x)];
		tmp -> cycle = 0;
		int val1 = get_first (tmp), val2 = get_last (tmp);
		if ((val1 == x && val2 == y) || (val1 == y && val2 == x)) {
			return;
		}
		int z1 = pos_in_treap (x);
		int z2 = pos_in_treap (y);
		if (z1 > z2)
			swap (z1, z2);
		Split_cnt (tmp, L[0], R[0], z1);
		Merge (R[0], R[0], L[0]);
	} else {
		node *tmp = root[get_root (x)];
		int z1 = pos_in_treap (x);
		int z2 = pos_in_treap (y);
		if (z1 > z2)
			swap (z1, z2);
		Split_cnt (tmp, L[0], R[0], z1);
	}
}

inline int get_ans (int x, int y) {
	if (get_root (x) != get_root (y))
		return -1;
	int z1 = pos_in_treap (x), z2 = pos_in_treap (y);
	if (z1 > z2)
		swap (z1, z2);
	int res = z2 - z1 - 1;
	if (root[get_root (x)] -> cycle)
		res = min (res, z1 + cnt (root[get_root (x)]) - z2 - 1);
	return res;
}

int main () {
	
	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif
	
	srand (1231);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m, q;

	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i)
		root[i] = new node (i);
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		add_edge (x, y);
	}	

	for (int i = 1; i <= q; ++i) {
		char q_type;
		int x, y;
		cin >> q_type >> x >> y;
		//cerr << "(" << i << ") ";
		if (q_type == '?') {
			cout << get_ans (x, y) << "\n";
		} else if (q_type == '+') {
			add_edge (x, y);
		} else {
			del_edge (x, y);
		}
		//cerr << "\n";
	}
	
	return 0;
}