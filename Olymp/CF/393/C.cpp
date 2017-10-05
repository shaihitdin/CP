#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

#define eb emplace_back

struct node {
	int sum, suff_sum;
	node (const node &a, const node &b) {
		sum = a.sum + b.sum;
		suff_sum = max (b.sum + a.suff_sum, b.suff_sum);
	}
	node () {
		sum = suff_sum = 0;
	}
} t[N * 4];

int n, p[N], x[N], add[N];

inline void upd (int v, int Tl, int Tr, int x, int el) {
	if (Tl > x || Tr < x)
		return;
	if (Tl == x && Tr == x) {
		t[v].sum = el;
		t[v].suff_sum = max (0, el);
		return;
	}
	int mid = (Tl + Tr) / 2;
	upd (v + v + 1, mid + 1, Tr, x, el);
	upd (v + v, Tl, mid, x, el);
	t[v] = node (t[v + v], t[v + v + 1]);
}

inline int get (int v, int Tl, int Tr, int l, int r, int &pre) {
	if (Tl > r || Tr < l)
		return 0;
	if (l <= Tl && Tr <= r) {
		int res = t[v].suff_sum + pre;
		pre += t[v].sum;
		//cerr << "COOOOOOO" << Tl << " " << Tr << " " << res << "\n";
		return max (res, 0);
	}
	int mid = (Tl + Tr) / 2;
	int ans = get (v + v + 1, mid + 1, Tr, l, r, pre);
	ans = max (ans, get (v + v, Tl, mid, l, r, pre));
	return ans;
}

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int type;
		cin >> p[i] >> type;
		if (type == 1) {
			cin >> x[p[i]];
			add[p[i]] = 1;
			upd (1, 1, n, p[i], 1);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!add[i])
			add[i] = -1, upd (1, 1, n, i, -1);
		
	
	vector <int> ans;

	for (int i = n; i >= 1; --i) {
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			int elementare = 0;
			int x = get (1, 1, n, mid, n, elementare);
			if (x > 0) {
				l = mid;
			} else {
				r = mid;
			}
		}
		int elementare = 0;
		//cerr << l << " " << get (1, 1, n, l, n, elementare) << "\n";
		/*
		for (int i = 1; i <= n; ++i) {
			cerr << add[i] << " ";
		}
		cerr << "\n";
		*/
		if (l == 0)
			ans.eb (-1);
		else
			ans.eb (x[l]);
		add[p[i]] = 0;
		upd (1, 1, n, p[i], 0);
	}
	
	reverse (ans.begin (), ans.end ());
	for (auto it : ans)
		cout << it << "\n";
	return 0;
}