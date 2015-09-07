#include <bits/stdc++.h>

using namespace std;

const int N = 5e5, sz = 2e9;

struct query {
	int y, sx, fx, flag;
};

struct node {
	int x;
	node *l, *r;
	node () {
		x = 0;
		l = r = 0;
	}
	node (const int &xx) {
		x = xx;
		l = r = 0;
	}
};

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r)
		return t -> x;
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	int mid = (Tl + 1ll * Tr) >> 1;
	return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline void upd_add (node *t, const int &Tl, const int &Tr, const int &x, const int &val) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		t -> x += val;
		return;
	}
	if (!t -> l)
		t -> l = new node (), t -> r = new node ();
	int mid = (Tl + 1ll * Tr) >> 1;
	
	upd_add (t -> l, Tl, mid, x, val);
	upd_add (t -> r, mid + 1, Tr, x, val);
	t -> x = t -> l -> x + t -> r -> x;
}

inline bool cmp (const query &lhs, const query &rhs) {
	if(lhs.y == rhs.y) {
		return (lhs.flag > rhs.flag);
	}
	return (lhs.y < rhs.y);
}


node *root;

query l[N];
int n, m, len;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> len;

	int cnt = 0;
	
	for (int i = 1; i <= n; ++i) {
		int sx, sy, fx, fy;
		cin >> sx >> sy;
		fx = sx + len + 1;
		fy = sy + len;
		l[++cnt].y = sy; l[cnt].sx = sx; l[cnt].fx = fx; l[cnt].flag = 1;
		l[++cnt].y = fy; l[cnt].sx = sx; l[cnt].fx = fx; l[cnt].flag = -1;
	}
	
	for (int i = 1; i <= m; ++i) {
		int sx, sy;
		cin >> sx >> sy;
		l[++cnt].y = sy, l[cnt].sx = sx, l[cnt].fx = sx; l[cnt].flag = 0;
	}
	
	sort (l + 1, l + cnt + 1, cmp);
	
	root = new node ();
	
	int ans = 0;
	
	for (int i = 1; i <= cnt; ++i) {
		if (l[i].flag == 0) {
			ans = max (ans, get (root, 0, sz, 0, l[i].sx));
		} else {
			if (l[i].flag == 1) {
				upd_add (root, 0, sz, l[i].sx, 1);
				upd_add (root, 0, sz, l[i].fx, -1);
			} else {
				upd_add (root, 0, sz, l[i].sx, -1);
				upd_add (root, 0, sz, l[i].fx, 1);			
			}
		}
	}
	
	cout << ans;
	
	return 0;
}