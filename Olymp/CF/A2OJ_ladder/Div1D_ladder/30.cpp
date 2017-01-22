/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 95542721, N = 1e5 + 100, K = 48;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

struct node {
	int vals[K], to_shift;
	node *l, *r;
	node (int a[K]) {
		memcpy (vals, a, sizeof (vals));
		l = r = 0;
		to_shift = 0;
	}
	node (node *Tl, node *Tr) {
		for (int i = 0; i < K; ++i)
			add (vals[i] = Tl -> vals[i], Tr -> vals[i]);
		to_shift = 0;
		l = Tl, r = Tr;
	}
};

node *root;
int b[N][K];

inline node * Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node (b[Tl]);
	int mid = (Tl + Tr) >> 1;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

int vs[K];

inline void push (node *t) {
	t -> to_shift %= K;
	if (!t -> to_shift)
		return;
	if (!t -> l) {
		for (int i = 0; i < K; ++i)
			vs[(i + t -> to_shift) % K] = t -> vals[i];
	} else {
		for (int i = 0; i < K; ++i)
			vs[(i + t -> l -> to_shift + t -> to_shift) % K] = t -> l -> vals[i];
		for (int i = 0; i < K; ++i)
			add (vs[(i + t -> r -> to_shift + t -> to_shift) % K], t -> r -> vals[i]);
		t -> l -> to_shift += t -> to_shift;
		t -> r -> to_shift += t -> to_shift;
	}
	cerr << t -> vals[0] << " ";
	memcpy (t -> vals, vs, sizeof (vs));
	cerr << t -> vals[0] << "\n";
	t -> to_shift = 0;
}

inline void upd (node *t, int Tl, int Tr, int l, int r) {
	push (t);
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		++t -> to_shift;
		push (t);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (t -> l, Tl, mid, l, r);
	upd (t -> r, mid + 1, Tr, l, r);
	*t = node (t -> l, t -> r);
}

inline int get (node *t, int Tl, int Tr, int l, int r) {
	push (t);
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> vals[0];
	int mid = (Tl + Tr) >> 1;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n, q;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> b[i][0];
		for (int j = 1; j < K; ++j) {
			b[i][j] = b[i][j - 1] * 1ll * b[i][j - 1] % bpr;
			b[i][j] = b[i][j] * 1ll * b[i][j - 1] % bpr;
		}
	}
	
	root = Build (1, n);	
	
	cin >> q;

	while (q--) {
		int q_type, l, r;
		cin >> q_type >> l >> r;
		if (q_type == 1)
			cout << get (root, 1, n, l, r) << "\n";
		else
			upd (root, 1, n, l, r);
	}
	
	return 0;
}