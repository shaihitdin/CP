#include <bits/stdc++.h>


using namespace std;

inline int RAND() {
	return (rand() * 1ll * rand()) % (1 << 30);
}

const int oo = 1e9 + 7;

struct node {
	int x, y, cnt;
	bool flag;
	node *l, *r;
	node() {
		x = 0;
		cnt = 1;
		flag = 0;
		y = RAND();
		l = r = 0;
	}
	node(const int &key) {
		x = key;
		cnt = 1;
		flag = 0;
		y = RAND();
		l = r = 0;
	}
};

inline void push(node *t) {
	if (t && t -> flag) {
		swap (t -> l, t -> r);
		if (t -> l)
			t -> l -> flag ^= 1;
		if (t -> r)
			t -> r -> flag ^= 1;
		t -> flag = 0;
	}
}

inline int cnt(node *it) {
	return it ? it -> cnt : 0;
}

inline void upd(node *it) {
	if (it)
		it -> cnt = cnt(it -> l) + cnt(it -> r) + 1;
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
	push(t);
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

const int N = 1e5 + 100;

node *root, *L[5], *R[5], *tmp;
char a[N], b[N];
int eq[N];

typedef long long ll;

ll k;
ll pw[20];

int p[N];

vector <int> g[N];

inline int get_p (const int &x) {
	return (x == p[x]) ? x : p[x] = get_p (p[x]);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	srand (time (0));
	
	int n, m;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		Merge (root, root, new node (i));
	}
	
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		Split_cnt (root, L[0], R[0], l - 1);
		Split_cnt (R[0], L[1], R[1], r - l + 1);
		L[1] -> flag ^= 1;
		Merge (R[0], L[1], R[1]);
		Merge (root, L[0], R[0]);
	}
	
	for (int i = 1; i <= n; ++i) {
		Split_cnt (root, L[0], root, 1);
		eq[i] = L[0] -> x;
	}
	
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	
	for (int i = 1; i <= n; ++i) {
		int x = i, y = get_p (eq[i]);
		p[x] = y;
	}

	for (int i = 1; i <= n; ++i) {
		g[get_p (i)].emplace_back (i);
	}
	
	int cnt = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (g[i].size () == 0)
			continue;
		char col = 0;
		for (auto it : g[i]) {
			if (a[it] == '?')
				continue;
			if (col == 0) {
				col = a[it];
			} else {
				if (col != a[it]) {
					cout << "Bad luck Allen";
					return 0;
				}
			}
		}
		if (col)
			for (auto it : g[i])
				b[it] = col;
		else
			for (auto it : g[i])
				b[it] = '?';
		if (!col)
			++cnt;
	}
	
	const int limit = 11;

	pw[0] = 1;

	for (int i = 1; i <= limit; ++i)
		pw[i] = pw[i - 1] * 26;
	
	--k;

	for (int i = 1; i <= n; ++i) {
		if (b[i] == '?') {
			if (cnt > limit) {
				for (auto it : g[get_p (i)])
					b[it] = 'a';
				--cnt;
			} else {
				char ch = 'a';
				--cnt;
				for (; ch <= 'z' && k >= pw[cnt]; ++ch, k -= pw[cnt]);
				if (ch > 'z') {
					cout << "Bad luck Allen";
					return 0;
				}
				for (auto it : g[get_p (i)])
					b[it] = ch;
			}
		}
	}
	
	if (k) {
		cout << "Bad luck Allen";
		return 0;
	}
	
	for (int i = 1; i <= n; ++i)
		cout << b[i];
	
	return 0;
}