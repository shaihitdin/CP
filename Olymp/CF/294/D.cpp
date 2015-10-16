#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

typedef long long ll;

struct node {
	ll x, add;
	int cnt;
	unsigned short y;
	node *l, *r;
	node () {
		x = y = 0;
		add = 0;
		l = r = 0;
		cnt = 1;
	}
	node (const ll &element) {
		x = element;
		y = rand();
		l = r = 0;
		add = 0;
		cnt = 1;
	}
};

inline void push (node *t) {
	if (t && t -> add) {
		t -> x += t -> add;
		if (t -> l)
			t -> l -> add += t -> add;
		if (t -> r)
			t -> r -> add += t -> add;
		t -> add = 0;
	}
}

inline int cnt (node *t) {
	return t ? t -> cnt : 0;
}

inline void upd (node *t) {
	if (t)
		t -> cnt = 1 + cnt (t -> l) + cnt (t -> r);
}

inline void Split (node *t, node *&l, node *&r, const int &x) {
	push (t);
	if (!t)
		l = r = 0;
	else if (t -> x <= x)
		Split (t -> r, t -> r, r, x), l = t;
	else
		Split (t -> l, l, t -> l, x), r = t;
	upd (l);
	upd (r);
	upd (t);
}

inline void Merge (node *&t, node *l, node *r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> y > r -> y)
		Merge (l -> r, l -> r, r), t = l;
	else
		Merge (r -> l, l, r -> l), t = r;
	upd (l);
	upd (r);
	upd (t);
}

inline void adding (node *t, const ll &to_add) {
	if (t)
		t -> add += to_add;
}

int sz;
int a[256];
string s;
vector <int> v[30];
node elements[N * 3];
node *root, *zero_el, *L, *R, *mid, *R1, *temp;
ll ans;
ll sum[N];

inline void out (node *t) {
	push (t);
	if (!t)
		return;
	out (t -> l);
	fprintf (stderr, "%d ", t -> x);
	out (t -> r);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	srand (53489340);
	ios_base :: sync_with_stdio (0);
	for (int i = 'a'; i <= 'z'; ++i)
		cin >> a[i];
	cin >> s;
	int n = s.size();
	s = '#' + s;	
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[s[i]];

	
	for (int i = n; i; --i)
		v[s[i] - 'a'].push_back (i);
	
	for (int i = 0; i < 26; ++i) {
		root = zero_el = 0;
		for (int j = 0; j < v[i].size(); ++j) {
			Split (root, L, R, -1);
			Split (R, mid, R1, 0);
			ans += cnt (mid);
			Merge (R, mid, R1);
			Merge (root, L, R);
			if (j + 1 == v[i].size())
				break;
			adding (root, a[i + 'a']);
			Split (root, L, R, -1);
			temp = &elements[sz++];
			*temp = node (0);
			Merge (R, temp, R);
			Merge (root, L, R);
			adding (root, sum[v[i][j] - 1] - sum[v[i][j + 1]]);
			/*
			cerr << "add here " << a[i + 'a'] << " " << sum[v[i][j] - 1] - sum[v[i][j + 1]] << "\n";
			out (root);
			fprintf (stderr, "\n");
			*/
		}
	}
	cout << ans;
	return 0;
}