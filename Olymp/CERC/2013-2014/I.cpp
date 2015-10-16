#include <bits/stdc++.h>

using namespace std;

inline int RAND() {
	return (rand() * 1ll * rand()) % (1 << 30);
}

const int oo = 1e9 + 7;

struct node {
	int x, y, cnt, mn;
	node *l, *r;
	node() {
		x = 0;
		cnt = 1;
		mn = oo;
		y = RAND();
		l = r = 0;
	}
	node(const int &key) {
		x = key;
		cnt = 1;
		y = RAND();
		mn = x;
		l = r = 0;
	}
};

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline int mn(node *it) {
	return it ? it -> mn : oo;
}

inline void upd(node *it) {
	if (it) {
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
		it -> mn = min (it -> x, min (mn (it -> l), mn (it -> r)));
	}
}

inline void Merge(node *&t, node *l, node *r) {
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
	if (cnt(t -> l) + 1 > x)
		Split_cnt(t -> l, l, t -> l, x), r = t;
	else
		Split_cnt(t -> r, t -> r, r, x - cnt(t -> l) - 1), l = t;
	upd(l);
	upd(r);
}

inline int get_min_pos(node *it, const int &x) {
	if (!it -> l && !it -> r)
		return x;
	if (mn (it) == it -> x)
		return x + cnt (it -> l);
	if (mn (it -> l) > mn (it -> r))
		return get_min_pos (it -> r, x + cnt (it -> l) + 1);
	else
		return get_min_pos (it -> l, x);
}


inline void output (node *it) {
	if (!it)
		return;
	output (it -> l);
	cerr << it -> x << " ";
	output (it -> r);
}

node *root, *L[5], *R[5];

const int N = 1e4 + 100;

int main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	srand (time (0));
	/*
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	*/
	int t;
	
	scanf ("%d", &t);
	
	while (t--) {
		
		int n;

		scanf ("%d", &n);
		
		root = nullptr;
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf ("%d", &x);
			Merge (root, root, new node (x));
		}
	
		vector <pair <int, int> > ans;
		
		for (int i = 1; i <= n; ++i) {
			while (get_min_pos (root, 1) != 1) {
				/*
				output (root);
				cerr << "\n";
				cerr << get_min_pos (root, 1) << " " << mn (root) << "\n\n";
				*/
				int x = get_min_pos (root, 1);
				int dist = x / 2;
				Split_cnt(root, L[0], R[0], x & 1);
				Split_cnt(R[0], L[1], R[1], dist);
				Split_cnt(R[1], L[2], R[2], dist);
				Merge (R[1], L[1], R[2]);
				Merge (R[0], L[2], R[1]);
				Merge(root, L[0], R[0]);
				ans.emplace_back (make_pair (i + (x & 1), i - 1 + x));
			}
			/*
			output (root);
			cerr << "\n";
			*/
			Split_cnt(root, L[0], root, 1);
		}
	
		
		assert (ans.size () <= 531441);

		printf ("%d\n", ans.size ());

		for (auto it : ans)
			printf ("%d %d\n", it.first, it.second);
	}
	
	return 0;
}