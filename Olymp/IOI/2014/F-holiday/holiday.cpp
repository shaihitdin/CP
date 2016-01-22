#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;
const int sz = 1 << 17;

int s;
int rev_cc[sz + 1];
int a[N];

struct node {
	int cnt;
	ll sum;
	node *l, *r;
	node () {
		cnt = sum = 0;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		cnt = Tl -> cnt + Tr -> cnt;
		sum = Tl -> sum + Tr -> sum;
		l = Tl, r = Tr;
	}
	node (const int &cnt1, const ll &sum1) {
		cnt = cnt1;
		sum = sum1;
		l = r = 0;
	}
};

node *root[N];

inline node * Build (const int &Tl, const int &Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tr + Tl) >> 1;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline node* upd (node *root, const int &Tl, const int &Tr, const int &x, const int &delta) {
	if (Tl > x || Tr < x)
		return root;
	if (Tl == x && Tr == x)
		return new node (root -> cnt + delta, root -> sum + delta * rev_cc[x]);
	int mid = (Tl + Tr) >> 1;
	return new node (upd (root -> l, Tl, mid, x, delta), upd (root -> r, mid + 1, Tr, x, delta));
}

inline ll get (node *m_root, node *p_root, const int &Tl, const int &Tr, const int &x) {
	if (Tl == Tr)
		return min (x, p_root -> cnt - m_root -> cnt) * 1ll * rev_cc[Tl];
	int mid = (Tl + Tr) >> 1;
	if (p_root -> r -> cnt - m_root -> r -> cnt > x)
		return get (m_root -> r, p_root -> r, mid + 1, Tr, x);
	else
		return get (m_root -> l, p_root -> l, Tl, mid, x - (p_root -> r -> cnt - m_root -> r -> cnt)) + (p_root -> r -> sum - m_root -> r -> sum);
}

inline pair <int, ll> get_f (const int &d, const int &l, const int &r, const int &move_cost) {
	ll res = 0;
	int f = l;
	for (int i = l; i <= r; ++i) {
		if (d <= abs (i - s) * move_cost)
			continue;
		ll x;
		if (l > s)
			x = get (root[s], root[i], 1, sz, d - (abs (i - s) * move_cost));
		else
			x = get (root[i - 1], root[s], 1, sz, d - (abs (i - s) * move_cost));
		if (x > res) {
			f = i;
			res = x;
		}
	}
	return make_pair (f, res);
}

inline void calc (const int &l, const int &r, const int &l1, const int &r1, const int &move_cost, ll dp[]) {
	if (l == r) {
		dp[l] = get_f (l, l1, r1, move_cost).second;
		return;
	}
	int mid = (l + r) >> 1;
	int f_f = get_f (mid, l1, r1, move_cost).first;
	if (r1 <= s) {
		calc (l, mid, f_f, r1, move_cost, dp);
		calc (mid + 1, r, l1, f_f, move_cost, dp);
	} else {
		calc (l, mid, l1, f_f, move_cost, dp);
		calc (mid + 1, r, f_f, r1, move_cost, dp);
	}
}

ll findMaxAttraction(int n, int start, int d, int attraction[]) {
	s = start;
	++s;
	if (d == 0)
		return 0;
    
    for (int i = n; i; --i)
    	a[i] = attraction[i - 1];

    map <int, int> cc;
    
    for (int i = 1; i <= n; ++i)
    	cc[a[i]] = 0;
    
    int zds_ = 1;
    for (auto it = cc.begin (); it != cc.end (); ++it, ++zds_) {
    	it -> second = zds_;
    	rev_cc[zds_] = it -> first;
    }
    
    for (int i = 1; i <= n; ++i)
    	a[i] = cc[a[i]];
    
    cc.clear ();
    
    root[0] = Build (1, sz);

    for (int i = 1; i <= n; ++i)
    	root[i] = upd (root[i - 1], 1, sz, a[i], 1);
    
    ll d1_1[250001], d1_2[250001], d2_1[250001], d2_2[250001];
    
    memset (d1_1, 0, sizeof (d1_1));
    memset (d1_2, 0, sizeof (d1_1));
    memset (d2_1, 0, sizeof (d1_1));
    memset (d2_2, 0, sizeof (d1_1));    

    calc (1, d, 1, s, 1, d1_1);
    calc (1, d, 1, s, 2, d1_2);
    if (s != n) {
    	calc (1, d, s + 1, n, 1, d2_1);
    	calc (1, d, s + 1, n, 2, d2_2);
	}
    for (int i = 1; i <= d; ++i) {
    	d1_1[i] = max (d1_1[i], d1_1[i - 1]);
    	d1_2[i] = max (d1_2[i], d1_2[i - 1]);
    	d2_1[i] = max (d2_1[i], d2_1[i - 1]);
    	d2_2[i] = max (d2_2[i], d2_2[i - 1]);
    }
    ll ans = 0;

    for (int i = 0; i <= d; ++i) {
    	ans = max (ans, d1_2[i] + d2_1[d - i]);
    	ans = max (ans, d1_1[i] + d2_2[d - i]);
    }
    
    return ans;
}
