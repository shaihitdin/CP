#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;

map <int, int> occurence;

int a[N], add[N];

struct node {
	// diff = distinct elements, len - length (l, r), len2 = len ^ 2
	int diff, diff_add;
	ll len, len2, ans, len_add;
	node *l, *r;
	node () {
		diff = 0;
		diff_add = 0;
		len_add = 0;
		len = len2 = ans = 0;
		l = r = 0;
	}
	node (node *lhs, node *rhs) {
		l = lhs;
		r = rhs;
		diff_add = 0;
		len_add = 0;
		len = lhs -> len + rhs -> len;
		len2 = lhs -> len2 + rhs -> len2;
		diff = lhs -> diff + rhs -> diff;
		ans = len2 * diff;
	}
};

node *root;

inline void push (node *t, const int &num) {
	if (t && (t -> len_add || t -> diff_add)) {
		t -> len2 = t -> len2 + (2 * t -> len_add) * (t -> len) + num * t -> len_add;
		t -> len += (num * t -> len_add);
		t -> diff += (num * t -> diff_add);
		cerr << t -> diff_add
		t -> ans += (t -> len2 * t -> diff_add);
		if (t -> l && t -> r) {
			t -> l -> len_add += t -> len_add;
			t -> l -> diff_add += t -> diff_add;
			t -> r -> len_add += t -> len_add;
			t -> r -> diff_add += t -> diff_add;
		}
		t -> len_add = 0;
		t -> diff_add = 0;
	}
}

/*
inline ll get (node *t, const int &l, const int &r, const int &Tl, const int &Tr) {
	push (t, Tr - Tl + 1);
	if (l <= Tl && Tr <= r)
		return t -> ans;
	if (Tl > r || Tr < l)
		return 0;
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, l, r, Tl, mid) + (t -> r, l, r, mid + 1, Tr);
}
*/

inline void upd (node *t, const int &l, const int &r, const int &len_add, const int &diff_add, const int &Tl, const int &Tr) {
	push (t, Tr - Tl + 1);
	if (l <= Tl && Tr <= r) {
		t -> len_add += len_add;
		t -> diff_add += diff_add;
		push (t, Tr - Tl + 1);
		return;
	}
	if (Tl > r || Tr < l)
		return;
	int mid = (Tl + Tr) >> 1;
	upd (t -> l, l, r, len_add, diff_add, Tl, mid);
	upd (t -> r, l, r, len_add, diff_add, mid + 1, Tr);
	t -> len = t -> l -> len + t -> r -> len;
	t -> len2 = t -> l -> len2 + t -> r -> len2;
	t -> diff = t -> l -> diff + t -> r -> diff;
	t -> ans = t -> l -> ans + t -> r -> ans;
}

inline node * Build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tl + Tr) >> 1;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

ll ans;
int n, sz = 1 << 17;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
		
	scanf ("%d", &n);	
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		add[i] = occurence[a[i]] + 1;
		occurence[a[i]] = i;
	}
	root = Build (0, sz - 1);
	for (int r = 1; r <= n; ++r) {
		upd (root, 1, r, 1, 0, 0, sz - 1);
		upd (root, add[r], r, 0, 1, 0, sz - 1);
		cerr << root -> ans << " " << root -> len2 << "\n";
		ans += root -> ans;
	}
	printf ("%I64d", ans);
	return 0;
}