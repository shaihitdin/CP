#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;

typedef long long ll;

inline int RAND() {
	return (rand() * 1ll * rand()) % (oo);
}

struct node {
	int x, y, add, cnt, eq;
	ll sum;
	node *l, *r;
	node() {
		x = add = 0;
		eq = oo;
		sum = 0;
		cnt = 1;
		y = RAND();
		l = r = 0;
	}
	node(const int &key) {
		x = sum = key;
		eq = oo;
		cnt = 1;
		add = 0;
		y = RAND();
		l = r = 0;
	}
};

inline void push(node *t) {
	if (t && (t -> add || t -> eq != oo)) {
		if (t -> eq != oo) {
			t -> sum = t -> cnt * 1ll * t -> eq;
			t -> x = t -> eq;
			if (t -> l)
				t -> l -> add = 0, t -> l -> eq = t -> eq;
			if (t -> r)
				t -> r -> add = 0, t -> r -> eq = t -> eq;
			t -> eq = oo;
		}
		if (t -> add) {
			t -> sum += t -> add * 1ll * t -> cnt;
			t -> x += t -> add;
			if (t -> l)
				t -> l -> add += t -> add;
			if (t -> r)
				t -> r -> add += t -> add;
			t -> add = 0;
		}
	}
}

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline ll sum(node *it) {
	return it ? it -> sum : 0;
}

inline void upd(node *it) {
	if (it) {
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
		it -> sum = sum(it -> l) + sum(it -> r) + it -> x;
	}
}

inline void Merge(node *&t, node *l, node *r) {
	push(l);
	push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge(l -> r, l -> r, r), t = l;
	else
		Merge(r -> l, l, r -> l), t = r;
	upd(t);
}

inline void Split_cnt(node *t, node *&l, node *&r, const int &x) {
	if (!t) {
		l = r = 0;
		return;
	}
	push(t);
	if (cnt(t -> l) + 1 > x)
		Split_cnt(t -> l, l, t -> l, x), r = t;
	else
		Split_cnt(t -> r, t -> r, r, x - cnt(t -> l) - 1), l = t;
	upd(l);
	upd(r);
}

inline void Split_key(node *t, node *&l, node *&r, const int &x) {
	if (!t) {
		l = r = 0;
		return;
	}
	push(t);
	if (t -> x >= x)
		Split_key(t -> l, l, t -> l, x), r = t;
	else
		Split_key(t -> r, t -> r, r, x), l = t;
	upd(l);
	upd(r);
}


inline int get_min(node *it) {
	if (!it)
		return oo;
	push(it);
	return min(get_min(it -> l), it -> x);
}

inline int get_max(node *it) {
	if (!it)
		return -oo;
	push(it);
	return max (get_max(it -> r), it -> x);
}

inline ll answer(const int &nn) {
	return (nn * 1ll * (nn - 1)) / 2;
}

inline ll get_ans (node *t) {
	if (!t)
		return 0;
	push (t);
	return get_ans (t -> l) + answer (t -> x) + get_ans (t -> r);
}

node *root, *L[5], *R[5];

const int N = 2e5;

int add[N], a[N], av[N];

int main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int h, k;
		cin >> h >> k;
		add[h - k + 1] += 1;
		add[h + 1] -= 1;
		++av[h];
	}
	
	for (int i = 1; i <= 1e5; ++i) {
		add[i] += add[i - 1];
		a[i] = add[i];
	}
	
	for (int i = 1e5; i >= 1; --i)
		av[i] += av[i + 1];
	
	for (int i = 1e5; i >= 1; --i) {
		if (get_max (root) <= a[i]) {
			Merge (root, root, new node (a[i]));
			continue;
		}
		Split_key (root, L[0], R[0], a[i]);
		int l = a[i], r = get_max (R[0]);
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			Split_key (R[0], L[1], R[1], mid);
			if (R[1] -> sum - R[1] -> cnt * 1ll * mid <= min (mid, av[i]) - a[i])
				r = mid;
			else
				l = mid;
			Merge (R[0], L[1], R[1]);
		}
		if (r == get_max (R[0])) {
			Merge (R[0], new node (a[i]), R[0]);
			Merge (root, L[0], R[0]);
			continue;
		}
		Split_key (R[0], L[1], R[1], r);
		a[i] += (R[1] -> sum - R[1] -> cnt * 1ll * r);
		push (R[1]);
		R[1] -> eq = r;
		assert (a[i] <= min (r, av[i]));
		if (a[i] < min (r, av[i])) {
			assert (R[1] -> cnt >= min (r, av[i]) - a[i]);
			Split_cnt (R[1], L[2], R[2], min (r, av[i]) - a[i]);
			L[2] -> add -= 1;
			Merge (L[1], L[1], L[2]);
			a[i] = min (r, av[i]);
			R[1] = R[2];
		}
		Merge (R[1], R[1], new node (a[i]));
		Merge (R[0], L[1], R[1]);
		Merge (root, L[0], R[0]);
	}
	
	cout << get_ans (root);

	return 0;
}