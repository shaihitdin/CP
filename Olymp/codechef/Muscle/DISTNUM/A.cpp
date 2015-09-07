#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1000, sz = 1 << 18, magic = 500, bpr = 1e9 + 7;

struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	} 
	node (const int &element) {
		x = element;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		x = Tl -> x + Tr -> x;
		if (x >= bpr)
			x -= bpr;
		l = Tl;
		r = Tr;
	}
	~node () {
	
	}
};

map <int, node*> root;
node *persistent[N];
node *any, *get_sum1, *get_sum2, *get_sum3, *get_pos;
vector <int> g[N];

int x[N], y[N], b[N], a[N], type[N], pos_q[N], nxt[N], _v[N], was[N];
int n, m;

inline void Del (node *t) {
	if (!t)
		return;
	if (t -> l)
		Del (t -> l);
	if (t -> r)
		Del (t -> r);
	delete t;
}

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (!t)
		return 0;
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x;
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline int get_kth (node *t, const int &Tl, const int &Tr, const int &x) {
	if (Tl == Tr)
		return Tl;
	int y = (t -> l) ? t -> l -> x : 0, mid = (Tl + Tr) >> 1;
	if (y >= x)
		return get_kth (t -> l, Tl, mid, x);
	return get_kth (t -> r, mid + 1, Tr, x - y);
}

inline void upd (node *t, const int &Tl, const int &Tr, const int &x, const int &to) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		t -> x = to;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	upd (t -> l, Tl, mid, x, to);
	upd (t -> r, mid + 1, Tr, x, to);
	t -> x = t -> l -> x + t -> r -> x;
	if (t -> x >= bpr)
		t -> x -= bpr;
}

inline void add (node *t, const int &Tl, const int &Tr, const int &x, const int &to) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		t -> x += to;
		return;
	}
	int mid = (Tl + Tr) >> 1;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	upd (t -> l, Tl, mid, x, to);
	upd (t -> r, mid + 1, Tr, x, to);
	t -> x = t -> l -> x + t -> r -> x;
	if (t -> x >= bpr)
		t -> x -= bpr;
}

inline node * upd_p (node *t, const int &Tl, const int &Tr, const int &x, const int &to) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node (to);
	int mid = (Tl + Tr) >> 1;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	if (x <= mid)
		return new node (upd_p (t -> l, Tl, mid, x, to), t -> r);
	return new node (t -> l, upd_p (t -> r, mid + 1, Tr, x, to));
}

inline int cube (const int &x) {
	return (((x * 1ll * x) % bpr) * x) % bpr;
}

inline int sqr (const int &x) {
	return (x * 1ll * x) % bpr;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	any = new node ();
	get_sum1 = new node ();
	get_sum2 = new node ();
	get_sum3 = new node ();
	
	scanf ("%d%d", &n, &m);
	
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d", &type[i]);
		if (type[i] == 1)
			scanf ("%d%d", &x[i], &y[i]);
		else if (type[i] == 2)
			scanf ("%d%d", &x[i], &y[i]);
		else if (type[i] == 3)
			scanf ("%d", &x[i]);
		else if (type[i] == 4)
			scanf ("%d%d", &x[i], &y[i]);
		else if (type[i] == 5)
			scanf ("%d%d", &x[i], &y[i]);
	}
	
	for (int i = 1; i <= n; ++i)
		upd (get_pos, 1, sz, i, 1);
	
	for (int i = 1; i <= m; ++i) {
		if (type[i] == 4) {
			int l = 0, r = n + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (get (get_pos, 1, sz, 1, mid) > x[i])
					r = mid;
				else
					l = mid;
			}
			g[l].emplace_back (i);
		}
	}	
	
	Del (get_pos);

	int j = 0;

	for (int i = 0; i < N; ++i) {
		//reverse (g[i].begin (), g[i].end ());
		if (a[i] != 0)
			b[++j] = a[i];
		for (auto it : g[i]) {
			pos_q[it] = ++j;
			b[j] = 0;
		}
		g[i].clear ();
	}
	
	for (int i = 1; i < N; ++i) {
		if (b[i] != 0) {
			if (!root.count (b[i]))
				root[b[i]] = new node ();
			upd (any, 1, sz, i, 1);
			upd (root[b[i]], 1, sz, i, 1);
			upd (get_sum1, 1, sz, i, b[i]);
			upd (get_sum2, 1, sz, i, sqr (b[i]));
			upd (get_sum3, 1, sz, i, cube (b[i]));
		}
	}
	
	int end = 1, check_point = 1;
	map <int, int> tmp;
	map <int, int> pos;
	vector <int> queries;

	for (int q_num = 1; q_num <= m; ++q_num) {
		if (end == q_num) {
			check_point = end;
			int q_cnt = 0;

			queries.resize (0);

			for (end = q_num; end <= m && q_cnt <= magic; ++end) {
				if (type[end] == 3 || type[end] == 4 || type[end] == 2) {
					++q_cnt;
					queries.emplace_back (end);
				}
			}			

			pos.clear ();
			
			for (int i = N - 2; i >= 1; --i) {
				if (b[i] == 0) {
					nxt[i] = N - 1;
					continue;
				}
				if (!pos.count (b[i]))
					nxt[i] = N - 1;
				else
					nxt[i] = pos[b[i]];
				pos[b[i]] = i;
			}
			
			/*
			for (int i = 1; i < N; ++i)
				Del (persistent[i]);
			*/

			persistent[1] = new node ();
			
			for (auto it : pos)
				upd (persistent[1], 1, sz, it.second, 1);


			for (int i = 2; i < N; ++i) {
				if (b[i - 1] != 0) {
					persistent[i] = upd_p (persistent[i - 1], 1, sz, i - 1, 0);
					persistent[i] = upd_p (persistent[i], 1, sz, nxt[i - 1], 1);
				} else {
					persistent[i] = persistent[i - 1];
				}
			}

			pos.clear ();
		}

		if (type[q_num] == 1) {
			//assert (0);
			int v1 = get_kth (any, 1, sz, x[q_num]), v2 = get_kth (any, 1, sz, y[q_num]);
			if (get (any, 1, sz, v1, v2) < 3) {
				printf ("0\n");
				continue;
			}
			int sum3 = get (get_sum3, 1, sz, v1, v2);
			int sum2 = get (get_sum2, 1, sz, v1, v2);
			int sum1 = get (get_sum1, 1, sz, v1, v2);
			int ans2 = (sum2 * 1ll * sum1 - sum3) % bpr;
			if (ans2 < 0)
				ans2 += bpr;
			int ans = (cube (sum1) - sum3 - ans2 * 3ll) % bpr;
			if (ans < 0)
				ans += bpr;
			
			printf ("%d\n", ans);
		
		} else if (type[q_num] == 2) {
			int v = get_kth (any, 1, sz, x[q_num]);
			pos[q_num] = v;
			upd (root[b[v]], 1, sz, v, 0);
			b[v] = y[q_num];
			upd (get_sum1, 1, sz, v, b[v]);
			upd (get_sum2, 1, sz, v, sqr (b[v]));
			upd (get_sum3, 1, sz, v, cube (b[v]));
			if (!root.count (b[v]))
				root[b[v]] = new node ();
			upd (root[b[v]], 1, sz, v, 1);
		} else if (type[q_num] == 3) {
			int v = get_kth (any, 1, sz, x[q_num]);
			pos[q_num] = v;
			was[q_num] = b[v];
			upd (any, 1, sz, v, 0);
			upd (get_sum1, 1, sz, v, 0);
			upd (get_sum2, 1, sz, v, 0);
			upd (get_sum3, 1, sz, v, 0);
			upd (root[b[v]], 1, sz, v, 0);
			y[q_num] = b[v];
			b[v] = 0;
		} else if (type[q_num] == 4) {
			if (!root.count (y[q_num]))
				root[y[q_num]] = new node ();
			upd (any, 1, sz, pos_q[q_num], 1);
			upd (root[y[q_num]], 1, sz, pos_q[q_num], 1);
			upd (get_sum1, 1, sz, pos_q[q_num], y[q_num]);
			upd (get_sum2, 1, sz, pos_q[q_num], sqr (y[q_num]));
			upd (get_sum3, 1, sz, pos_q[q_num], cube (y[q_num]));
			b[pos_q[q_num]] = y[q_num];
		} else if (type[q_num] == 5) {
			int v1 = get_kth (any, 1, sz, x[q_num]), v2 = get_kth (any, 1, sz, y[q_num]);
			int ans = get (persistent[v1], 1, sz, v1, v2);
			for (auto i : queries) {
				if (type[i] == 3 && v1 <= pos_q[i] && pos_q[i] <= v2)
					--tmp[y[i]];
				else if (type[i] == 4 && v1 <= pos_q[i] && pos_q[i] <= v2)
					++tmp[y[i]];
				else if (type[i] == 2 && v1 <= pos_q[i] && pos_q[i] <= v2)
					--tmp[was[i]], ++tmp[y[i]];
			}
			for (auto it : tmp)
				if (get (root[it.first], 1, sz, v1, v2) == it.second && it.second > 0)
					++ans;
			tmp.clear ();
			printf ("%d\n", ans);
		}

	}
	
	exit (0);
}